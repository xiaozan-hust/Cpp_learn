#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

// 定义一个结构体来存储位姿信息
struct Pose {
    double x;
    double y;
    double z;
    double qx;
    double qy;
    double qz;
    double qw;
};

// 读取Odometry数据的函数
std::vector<Pose> readOdometryData(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<Pose> poses;
    Pose pose;

    if (!file.is_open()) {
        std::cerr << "Failed to open file " << filename << std::endl;
        return poses;
    }

    while (file >> pose.x >> pose.y >> pose.z >> pose.qx >> pose.qy >> pose.qz >> pose.qw) {
        poses.push_back(pose);
    }

    file.close();
    return poses;
}

// 计算欧氏距离的函数
double computeEuclideanDistance(const Pose& pose1, const Pose& pose2) {
    return std::sqrt(std::pow(pose1.x - pose2.x, 2) + 
                     std::pow(pose1.y - pose2.y, 2) + 
                     std::pow(pose1.z - pose2.z, 2));
}

// 计算RPE的函数
double computeRPE(const std::vector<Pose>& truePoses, const std::vector<Pose>& estimatedPoses) {
    double totalError = 0.0;
    size_t N = std::min(truePoses.size(), estimatedPoses.size());

    for (size_t i = 0; i < N; ++i) {
        totalError += computeEuclideanDistance(truePoses[i], estimatedPoses[i]);
    }

    return totalError / static_cast<double>(N);
}

int main() {
    // 读取真值和估计的Odometry数据
    std::string trueFilename = "/home/jxj/graduate/ndt_ws/src/laser_ndt_location/tra/大地图静态/ground_truth.txt";
    std::string estimatedFilename = "/home/jxj/graduate/ndt_ws/src/laser_ndt_location/tra/大地图静态/laser_odom.txt";

    std::vector<Pose> truePoses = readOdometryData(trueFilename);
    std::vector<Pose> estimatedPoses = readOdometryData(estimatedFilename);

    if (truePoses.empty() || estimatedPoses.empty()) {
        std::cerr << "Failed to read odometry data" << std::endl;
        return 1;
    }

    // 计算RPE
    double rpe = computeRPE(truePoses, estimatedPoses);
    std::cout << "RPE: " << rpe << std::endl;

    return 0;
}
