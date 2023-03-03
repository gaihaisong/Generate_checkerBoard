#include<iostream>
#include<opencv4/opencv2/core/core.hpp>
#include<opencv4/opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int perBoardPixel = 100;
int radius=50;
const cv::Size boardSize(13,9);
const cv::Size resolution(1920,1080);
int main()
{
	int basisHeight = (resolution.height - perBoardPixel*boardSize.height) / 2;
	int basisWidth = (resolution.width - perBoardPixel*boardSize.width) / 2;
    cout<<"basisHeight:"<<basisHeight<<",basis_width:"<<basisWidth<<endl;
	if( basisHeight < 0  ||  basisWidth < 0)
	{
		cout<<"Resolution doesn't match!"<<endl;
	}
	cv::Mat image(resolution,CV_8UC1,cv::Scalar::all(255));
	int flag = 0;
	for(int j = 0;j < boardSize.height;j++)
	{
        // int h=j;
        // if(j%2==1)
        
		for(int i = 0;i < boardSize.width;i++)
		{
            // int   h=0;
            // h=2*i;
			
			if((i>=boardSize.width/2-1)&&(i<=boardSize.width/2+1)&&(j>=boardSize.height/2-1)&&(j<=boardSize.height/2+1))
			      continue;

			flag = (i+j) % 2;
			if(flag == 1)
			{
              
				for(int n = j * perBoardPixel;n < (j+1) * perBoardPixel;n++)
					for(int m = i * perBoardPixel;m < (i+1) * perBoardPixel;m++)
						image.at<uchar>(n + basisHeight,m + basisWidth) = 0;
			}
            // cout << j << " ," << i << ", "  << endl;
            // Point center(100+radius + h * perBoardPixel, 150+radius + j * perBoardPixel);
            // circle(image, center, radius, Scalar(0, 0, 0), -1);
            
        }
	}
    cv::imshow("haha", image);
    cv::imwrite("chessBoard1.png", image);
    cv::waitKey(0);
    return 0;
}
