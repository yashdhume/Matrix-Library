#include <iostream>
#include <stdlib.h>
#include "Mat.h"

using namespace std;


Mat::Mat(int r, int c){
	row = r;
	col = c;
	myMat= new double*[row];
	for (int i=0; i<row; i++){
		myMat[i] = new double[col];
    }
};
Mat::Mat(){
    row = 0;
    col = 0;
    myMat[0]=new double[0];
}
Mat::Mat(const Mat& m){
	row = m.row;
	col = m.col;
	myMat= new double*[row];
	for (int i=0; i<row; i++){
		myMat[i] = new double[col];
    }
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			myMat[i][j] = m.myMat[i][j];
		}
	}
}

Mat::~Mat(){
	for (int i=0; i<row; i++){
		delete[] myMat[i];
		}
	delete[] myMat;
};
void Mat::ones(){
    for (int i =0; i<row; i++){
        for(int j=0; j< col;j++){
            myMat[i][j] = 1;
        }
    }
}
void Mat::zero(){
    for (int i =0; i<row; i++){
        for(int j=0; j< col;j++){
            myMat[i][j] = 0;
        }
    }
}
void Mat::rnd(){
    srand(time(NULL));
    for (int i =0; i<row; i++){
        for(int j=0; j< col;j++){
            myMat[i][j] = rand()%2;
        }
    }
}

Mat Mat::operator+ (const Mat& m){
    Mat sum(row,col);
    if (row!=m.row||col!=m.col){
        cerr << "Invalid Input"<<endl;
        return Mat();
    }
    else{
        for (int i=0; i<row; i++){
            for (int j=0; j<col; j++){
                sum.myMat[i][j] = m.myMat[i][j]+ myMat[i][j] ;
            }
        }
        return sum;
    }
}

Mat Mat::operator-(const Mat& m){
    Mat sub(row,col);
    if (row!=m.row||col!=m.col){
        cerr << "Invalid Input"<<endl;
        return Mat();
    }
    else{
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			sub.myMat[i][j] = myMat[i][j] - m.myMat[i][j];
		}
	}
	return sub;
    }
}
Mat operator*(const Mat& m, const Mat& m2){
    if (m.col == m2.row){
        Mat multi(m.row, m2.col);
        for(int i =0; i< m2.col; i++){
            for (int j=0; j< m.row; j++){
                int sum =0;
                for (int k =0; k<m.col;k++){
                    sum+=m.myMat[i][k]*m2.myMat[k][j];
                }
               multi.myMat[i][j] =sum;
            }
        }
        return multi;
    }
    else{
		cerr << "invalid Input";
		return m;
	}

}
Mat Mat::operator=(const Mat& m){
    row = m.row;
    col = m.col;
    for (int i=0; i<row; i++){
      for (int j=0; j<col; j++)
        myMat[i][j]= m.myMat[i][j];
    }
   return *this;

}
Mat Mat::operator+(const double& x){
    Mat addScal(row,col);
    for (int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            addScal.myMat[i][j] = x+ this->myMat[i][j];
        }
    }
    return addScal;
}
Mat Mat::operator-(const double& x){
    Mat subScal(row,col);
    for (int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            subScal.myMat[i][j] =  this->myMat[i][j]-x;
        }
    }
    return subScal;
}

Mat Mat::operator*(const double& x){
    Mat multiScal(row,col);
    for (int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            multiScal.myMat[i][j] = x*this->myMat[i][j];
        }
    }
    return multiScal;
}
Mat Mat::operator/(const double& x){
    Mat divScal(row,col);
    for (int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            divScal.myMat[i][j] = this->myMat[i][j]/x;
        }
    }
    return divScal;
}
Mat Mat::operator+=(const Mat& m) {
if (row!=m.row||col!=m.col){
        cerr << "Invalid Input"<<endl;
        return Mat();
    }
    else{
        for(int i=0; i<row; i++) {
            for(int j=0; j<col;j++)
                myMat[i][j] += m.myMat[i][j] ;
        }

        return *this ;
    }
}
Mat Mat::operator-=(const Mat& m) {
    if (row!=m.row||col!=m.col){
        cerr << "Invalid Input"<<endl;
    }
    else{
        for(int i=0; i<row; i++) {
            for(int j=0; j<col;j++)
                myMat[i][j] -= m.myMat[i][j] ;
        }

        return *this ;
    }
}
Mat Mat::operator*=(const Mat& m) {
    Mat matStar(row, m.col) ;
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < m.col ; j++){
            matStar.myMat[i][j] = 0 ;
                for(int k= 0 ; k < row ; k++){
                    myMat[i][j] = myMat[i][j] + (myMat[i][k]*m.myMat[k][j]) ;
                }
            }
        }


    return *this ;
}
Mat Mat::operator/=(const Mat& m) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col;j++)
            myMat[i][j] /= m.myMat[i][j] ;
    }

    return *this ;
}
Mat Mat::operator/=(const double& x) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col;j++)
            myMat[i][j] /= x ;
    }

    return *this ;
}
Mat Mat::operator+=(const double& x) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col;j++)
            myMat[i][j] += x ;
    }

    return *this ;
}
Mat Mat::operator-=(const double& x) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col;j++)
            myMat[i][j] -= x ;
    }

    return *this ;
}
Mat Mat::operator*=(const double& x) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col;j++)
            myMat[i][j] *= x ;
    }

    return *this ;
}
double* Mat:: operator[](int r){
	return myMat[r];
}


ostream& operator<<(ostream& os, const Mat& m) {
    os<< "Numbe of Rows: " << m.row <<" Number of Colomns "<<m.col << endl;
   for (int i = 0; i < m.row; i++)    {
      for (int j = 0; j < m.col; j++)
        os << m.myMat[i][j] << "  ";
      os << endl;
   }
   return os;
}
istream &operator>>(istream &is, Mat &m){
    for (int i=0; i<m.row; i++){
		delete[] m.myMat[i];
    }
	delete[] m.myMat;

    is >> m.row >> m.col;
    m.myMat=new double*[m.row];
    for (int i = 0; i < m.row; i++){
        m.myMat[i]=new double[m.col];
       for (int j = 0; j < m.col; j++)
           is >> m.myMat[i][j];
   }
   return is;
}


