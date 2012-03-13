#include <vector>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

#define BAYESIAN_NUMBER_NEAREST   200
#define BAYESIAN_SIGMA            8.f
#define BAYESIAN_SIGMA_C          5.f
#define BAYESIAN_MAX_CLUS           3

class BayesianMatting
{
public:
    BayesianMatting(Mat img, Mat trimap);
    ~BayesianMatting();
    
    void setParameters(int n=BAYESIAN_NUMBER_NEAREST, double sigma=BAYESIAN_SIGMA, double sigmaC=BAYESIAN_SIGMA_C);
    double solve();
    
private:
    void initialize();
    vector<Point> getContour(Mat trimap);
    
    Mat img, fgImg, bgImg;
    Mat maskFg, maskBg, maskUnknown;
    Mat trimap, alphamap;
    int nearest;
    double sigma, sigmaC;
};
