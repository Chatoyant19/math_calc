#include <iostream>
#include <vector>
#include <eigen3/Eigen/Geometry>
#include <stdlib.h>
using namespace std;

//python:signal.correlate()
//cross-correlate
typedef std::vector<Eigen::Vector3d, Eigen::aligned_allocator<Eigen::Vector3d>> VelocityVector;
vector<double> calculateCorrelation(const vector<double>& vec1, const vector<double>& vec2, string mode)
{
    int M = vec1.size();
    int N = vec2.size();
    vector<double> res_full(M+N-1, 0);
    vector<double> res_same(M, 0);
    vector<double> res_valid(abs(M-N)+1);
    // vector<double> res(M+N-1,0.0);
    //M=N
    int start_1 = 0, end_1 = 0;
    int start_2 = N, end_2 = N;
    for(int i = 0; i < M+N-1; ++i)
    {
       end_1 = (end_1 == M ? M : ++end_1);
       start_2 = (start_2 == 0? 0 : --start_2);
       if(i > N-1) start_1++;
       if(i > M-1) end_2--;
       double result = 0;
       for(int j = start_1, k = start_2; j < end_1, k < end_2; ++j, ++k)
       {
           result += (vec1[j]*vec2[k]);
       }
       res_full[i] = result;
    }
    if(mode == "full")
        return res_full;
    else if(mode == "same")
    {
        int begin = N/2-1;
        for(int i = begin, j = 0; i < begin + M, j < M; ++i, ++j)
        {
            res_same[j] = res_full[i];
        }
        return res_same;
    }
    else if(mode == "valid")//valid
    {
        if(M == N)
        {
            res_valid[0] = res_full[M-1];   
        }
        else
        {
            int len = M > N ? N-1: M-1;
            for(int i = len, j = 0; i < abs(M-N)+1+len, j < abs(M-N)+1; ++i, ++j)
            {
                res_valid[j] = res_full[i];
            }
        }
        return res_valid;
    }  
}

VelocityVector calculateEigenCorrelation(const VelocityVector& vec1, const vector<double>& vec2, string mode)
{
    int M = vec1.size();
    int N = vec2.size();
    VelocityVector res_full(M+N-1, Eigen::Vector3d(0,0,0));
    VelocityVector res_same(M, Eigen::Vector3d(0,0,0));
    int start_1 = 0, end_1 = 0;
    int start_2 = N, end_2 = N;
    for(int i = 0; i < M+N-1; ++i)
    {
       end_1 = (end_1 == M ? M : ++end_1);
       start_2 = (start_2 == 0? 0 : --start_2);
       if(i > N-1) start_1++;
       if(i > M-1) end_2--;
       Eigen::Vector3d result(0, 0, 0);
       for(int j = start_1, k = start_2; j < end_1, k < end_2; ++j, ++k)
       {
           result.x() += (vec1[j].x()*vec2[k]);
           result.y() += (vec1[j].y()*vec2[k]);
           result.z() += (vec1[j].z()*vec2[k]);
       }
       res_full[i] = result;
    }
    if(mode == "full")
        return res_full;
    else if(mode == "same")
    {
        int begin = N/2-1;
        for(int i = begin, j = 0; i < begin + M, j < M; ++i, ++j)
        {
            res_same[j] = res_full[i];
        }
        return res_same;
    }
}

int main()
{
    // vector<double> r;
    // vector<double> res1 = {1,2,4};
    // vector<double> res2 = {3,2,1};
    // r = calculateCorrelation(res1,res2,"full");
    // for(int i = 0; i< r.size(); ++i)
    // {
    //     cout << r[i] << endl;
    // }
    VelocityVector vec1;
    Eigen::Vector3d v1(1,2,3);
    Eigen::Vector3d v2(4,5,6);
    Eigen::Vector3d v3(7,8,9);
    vec1.push_back(v1);
    vec1.push_back(v2);
    vec1.push_back(v3);
    
    cout << 
    // vector<double> vec2 = {0.4, 0.4};
    // VelocityVector r = calculateEigenCorrelation(vec1, vec2, "same");  
    // for(int i = 0; i < r.size(); ++i)
    // {
    //     cout << r[i].x() << " " << r[i].y() << " " << r[i].z() << endl;
    // } 
}