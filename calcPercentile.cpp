#include <iostream>
#include <vector>
#include <cmath>
#include <eigen3/Eigen/Geometry>
using namespace std;

double calculatePercentile(const vector<double>& vec, double p)
{
    int n = vec.size();
    p = p / 100;
    double tmp = (n-1) * p;
    int i = floor(tmp);
    double j = tmp - i;
    double res = (1-j) * vec[i] + j*vec[i+1];
    return res;
}

int main()
{
    vector<double> vec = {1,2,3,4,5,6,7,8,9};
    double p =30;
    double res = calculatePercentile(vec, p);
    // cout << res << endl;
    std::vector<Eigen::Vector3d, Eigen::aligned_allocator<Eigen::Vector3d>> VelocityVector;
    VelocityVector.push_back(Eigen::Vector3d(0,1,2));
    VelocityVector.push_back(Eigen::Vector3d(2,1,3));
    VelocityVector.push_back(Eigen::Vector3d(4,5,6));
    VelocityVector.push_back(Eigen::Vector3d(10,11,12));
    // vector<double> vec1;
    // for(int i = 0; i < VelocityVector.size(); ++i)
    // {
    //     vec1.push_back(VelocityVector[i].x());
    //     vec1.push_back(VelocityVector[i].y());
    //     vec1.push_back(VelocityVector[i].z());
    // }
    // for(int i = 0; i< vec1.size(); ++i)
    // {
    //     cout << vec1[i] << " "; 
    // }
    std::vector<Eigen::Vector3d, Eigen::aligned_allocator<Eigen::Vector3d>> v2;
    for(int i = 0; i< VelocityVector.size(); ++i)
    {
        v2.push_back(VelocityVector[i]);
    }
    cout << v2[0];
}
