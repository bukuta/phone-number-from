#include <iostream>
#include "Logger.hpp"

#include <eigen3/Eigen/Eigen>

using namespace Eigen;
using namespace std;

int main(int argc, char *argv[]) {
  // 初始化
  MatrixXd m(2, 2);
  m(0, 0) = 3;
  m(1, 0) = 2.5;
  m(0, 1) = -1;
  m(1, 1) = m(1, 0) + m(0, 1);
  Logger::warn("m:");
  std::cout << m << std::endl;

  // 初始化
  Logger::warn("mm<<:");
  MatrixXd mm(2, 2);
  mm << 1, 2, 3, 4;
  cout << mm << endl;

  if (mm.determinant() != 0) {
    Logger::error("求逆");
    cout<<"origin:"<<endl<<mm<<endl;
    cout<<"mm.determinant()"<<endl;
    cout<<mm.determinant()<<endl;
    cout << "mm.inverse()" << endl;
    cout << mm.inverse() << endl;
    cout<<"mm.inverse()*mm"<<endl<<mm.inverse()*mm<<endl;
    cout << "mm.adjoint()/|mm|" << endl;
    cout << mm.adjoint() << endl;
    cout << mm.adjoint() / mm.determinant() << endl;
  }

  // 初始化2*2
  Matrix2d m2d;
  m2d = m;
  Logger::warn("m2d:");
  cout << m2d << endl;

  // normal
  Logger::warn("m2d.norm():");
  cout << m2d.norm() << endl;

  // size
  Logger::warn("m2d.size()");
  cout << m2d.size() << endl;
  Logger::warn("m2d.rows()");
  cout << m2d.rows() << endl;
  Logger::warn("m2d.cols()");
  cout << m2d.cols() << endl;

  // m(1) 1维方式读取，列优先
  Logger::warn("m(1)");
  cout << m(0) << "=" << m(0, 0) << endl;
  cout << m(1) << "=" << m(1, 0) << endl;
  cout << m(2) << "=" << m(0, 1) << endl;
  cout << m(3) << "=" << m(1, 1) << endl;

  // resize
  Logger::warn("resize(2,3)");
  MatrixXd m23d = MatrixXd::Random(2, 3);
  m23d << 1, 2, 3, 4, 5, 6;
  cout << m23d << endl;
  Logger::warn("resize(2,3).after");
  m23d.resize(3, 2);
  cout << m23d << endl;

  Logger::warn("sum:");
  cout << mm << endl;
  cout << "=" << mm.sum() << endl;

  Logger::warn("determinant:");
  cout << mm.determinant() << endl;

  Logger::warn("normalize():");
  mm.normalize();
  cout << mm << endl;

  Logger::warn("矩阵的秩:");
  FullPivLU<MatrixXd> lu_mm(mm);
  cout << lu_mm.matrixLU() << endl;
  cout << lu_mm.rank() << endl;

  Logger::warn("特征值：mm.eigenvalues()");
  cout << mm.eigenvalues() << endl;

  Logger::warn("特征向量 eigenvectors()");
  SelfAdjointEigenSolver<MatrixXd> solver(mm);
  cout<<solver.info()<<endl;
  cout<<solver.eigenvectors()<<endl;

  Logger::error("特殊矩阵生成：");
  Logger::warn("单位矩阵matrixXd::Identity()");
  cout << MatrixXd::Identity(2, 2) << endl;

  Logger::warn("零矩阵matrixXd::Zeros(x,y)");
  cout << MatrixXd::Zero(2, 3) << endl;

  Logger::warn("全1矩阵matrixXd::Ones(x,y)");
  cout << MatrixXd::Ones(2, 3) << endl;

  Logger::warn("线性向量VectorXd::LinSpaced(10,1,100)");
  cout << VectorXd::LinSpaced(10, 1, 5) << endl;

  Logger::warn("随机矩阵MatrixXd::Random(3,3)");
  MatrixXd m2 = MatrixXd::Random(3, 3);
  cout << m2 << endl;

  Logger::error("矩阵分块");
  VectorXd v(3);
  v << 1, 2, 3;
  Logger::warn("vector.head(n)");
  cout << v.head(2) << endl;
  Logger::warn("matrix.row()");
  cout << m2.row(0) << endl;
  cout << m2.row(1) << endl;
  cout << m2.row(2) << endl;
  Logger::warn("matrix.col()");
  cout << "col(0):" << m2.col(0) << endl;
  cout << "col(1):" << m2.col(1) << endl;
  cout << "col(2):" << m2.col(2) << endl;
  Logger::warn("matrix.block(i,j,rows,cols)");
  cout << m2.block(1, 1, 2, 2) << endl;

  Logger::error("矩阵元素交换");
  MatrixXd ms1 = MatrixXd::Random(2, 3);
  MatrixXd ms2 = MatrixXd::Zero(3, 2);
  ms2.row(0) = ms1.col(0);
  cout << ms1 << endl;
  cout << "==" << endl;
  cout << ms2 << endl;

  Logger::warn("伴随矩阵.adjoint()");
  ms1.adjoint();
  cout << ms1.adjoint() << endl;

  Logger::warn("转秩矩阵:transpose()");
  cout << ms1 << endl;
  cout << "==" << endl;
  cout << ms1.transpose() << endl;

  Logger::warn("对角线:diagonal");
  cout << ms1.diagonal() << endl;

  Logger::warn("rot90");
  cout << ms1 << endl;
  cout << "==" << endl;
  cout << ms1.transpose().colwise().reverse() << endl;

  Logger::warn("共轭矩阵 conjugate()");
  cout << ms1 << endl;
  cout << "===" << endl;
  MatrixXd conj = ms1.conjugate();
  cout << conj << endl;

  Logger::warn("逆矩阵");
  cout << m << endl;
  cout << m.inverse() << endl;
  cout << m * m.inverse() << endl;

  m2 = (m2 + MatrixXd::Constant(3, 3, 1.2) * 50);
  Logger::warn("m2:");
  cout << m2 << endl;

  Logger::warn("m*v:");
  cout << m23d << endl;
  cout << "*" << endl;
  cout << m23d.transpose() << endl;
  cout << "=" << endl;
  cout << m23d * m23d.transpose() << endl;

  Logger::error("单个元素操作？");
  Logger::warn("点乘");
  // cout<<m23d.dot(m23d.transpose())<<endl;
  Logger::warn("matrix.array()");
  cout << m23d.array() << endl;
  Logger::warn("matrix.sin()");
  cout << m23d.array().sin() << endl;

  Logger::error("解方程:");
  Matrix2d AA;
  AA << 2, 3, 4, 5;
  Vector2d b;
  b << 19, 8;

  Logger::warn("A_1:逆矩阵: ok,前提是可逆");

  cout << "determinant:" << AA.determinant() << endl;

  if (AA.determinant() - 0 > 1e-6) {
    MatrixXd AA_1 = AA.inverse();
    cout << "AA_1" << endl;
    cout << AA_1 << endl;

    Vector2d r = AA_1 * b;
    cout << r << endl;
    cout << "AA*r=" << endl;
    cout << AA * r << endl;
  } else {
    cout << "determinant==0" << endl;
    cout << "不能计算逆矩阵" << endl;
  }
  // Logger::warn("A.ldlt().solve(): wrong");
  // cout << AA.ldlt().solve(b) << endl;

  Logger::warn("A.lu().solve(b): ok");
  cout << AA.lu().solve(b) << endl;

  Logger::error("A.llt().solve(b):");
  // cout << AA.selfadjointView().sovle(b) << endl;
  // MatrixXd rrr =  AA.llt();
  // cout<<rrr<<endl;

  Logger::warn("QR分解：A.colPivHouseholderQr().solve(b):");
  cout << AA.colPivHouseholderQr().solve(b) << endl;
  Logger::warn("A.fullPrivLu().sovle(b):");
  cout << AA.fullPivLu().solve(b) << endl;

  Logger::warn("A.partialPivLu().solve(b):");
  cout << AA.partialPivLu().solve(b) << endl;

  Logger::warn(" AA.householderQr().resolve(b)");
  cout << AA.householderQr().solve(b) << endl;

  Logger::warn("AA.fullPivHouseholderQr().solve(b)");
  cout << AA.fullPivHouseholderQr().solve(b) << endl;

  // SVD解方程
  Logger::warn("A.svd().solve(b): ok");
  JacobiSVD<MatrixXd> svd(AA, ComputeFullU | ComputeFullV);
  cout << AA.jacobiSvd(ComputeFullU | ComputeFullV).solve(b) << endl;

  cout << "svd:" << endl;
  cout << "svd.matrixU():" << endl;
  cout << svd.matrixU() << endl;
  cout << "svd.matrixV():" << endl;
  cout << svd.matrixV() << endl;

  cout << "solve:" << endl;

  // QR分解 解方程
  Logger::warn("QR 解方程");
  HouseholderQR<MatrixXd> qr0;
  qr0.compute(AA);
  cout << qr0.matrixQR() << endl;
  MatrixXd Q0 = qr0.householderQ();
  MatrixXd R0 = qr0.matrixQR().triangularView<Upper>();
  VectorXd qTb = Q0.transpose() * b;

  cout << "Q:" << endl << Q0 << endl;
  cout << "R:" << endl << R0 << endl;
  cout << "qT*b" << endl;
  cout << qTb << endl;
  cout << "R.inverse()" << endl;
  cout << R0.inverse() << endl;
  cout << "R-1*QT*b" << endl;
  cout << R0.inverse() * qTb << endl;

  cout << "手动计算:" << endl;
  Vector2d xy;
  xy(1) = qTb(1) / R0(1, 1);
  cout << xy << endl;
  xy(0) = (qTb(0) * R0(1, 1) - qTb(1) * R0(0, 1)) / (R0(0, 0) * R0(1, 1));
  cout << xy << endl;
  // cout << qr0.matrixQR().resolve;

  Logger::error("QR分解");
  Matrix3d A;
  A << 1, 1, 1, 2, -1, -1, 2, -4, 5;
  HouseholderQR<Matrix3d> qr;
  qr.compute(A);
  MatrixXd R = qr.matrixQR().triangularView<Upper>();
  MatrixXd Q = qr.householderQ();
  cout << "QR2():" << endl;
  cout << "A " << endl << A << endl << endl;
  cout << "qr.matrixQR():" << endl << qr.matrixQR() << endl << endl;
  cout << "R" << endl << R << endl << endl;
  cout << "Q" << endl << Q << endl << endl;
  cout << "Q*R" << endl << Q * R << endl << endl;
}