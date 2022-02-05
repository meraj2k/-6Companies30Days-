
//    https://leetcode.com/problems/generate-random-point-in-a-circle


class Solution {
public:
    double uniform()
    {
        return (double)rand() / RAND_MAX;
    }
    double radius,x_center, y_center;
    Solution(double radius, double x_center, double y_center) {
        this->radius=radius;
        this->x_center=x_center;
        this->y_center=y_center;
    }
    
    vector<double> randPoint() {
        double theta=2*3.14159265*uniform();
        double d=sqrt(uniform())*radius;
        return {x_center+d*cos(theta),d*sin(theta)+y_center};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */