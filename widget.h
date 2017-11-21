#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class Widget;
}

//窗口类
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    //用一个枚举，标志黑白棋状态
    enum ChessStatus{Empty, Black, White};

    //初始化棋盘状态
    void initChess();

    //切换角色
    void changeRole();

    //统计个数
    void showScore();

    // 吃子规则的参数：棋盘数组坐标位置(x y)、棋子状态数组(chess)、棋子的当前角色(注意其变量的写法)
    // eatChess默认为true, 横着或竖着的格数(gridNum)默认值为8
    int judgeRule(int x, int y, void *chess, ChessStatus currentRole, bool eatChess=true, int gridNum=8);

    //机器下子
    void machinePlay();

protected:
    void paintEvent(QPaintEvent *); //绘图事件，画棋盘，画棋子
    void mousePressEvent(QMouseEvent *); //鼠标按下事件，获取当前点击的坐标，下子坐标
    void mouseMoveEvent(QMouseEvent *); //鼠标移动事件，移动窗口


private slots:
    void on_toolButton_2_clicked();

    void on_toolButtonBegin_clicked();

private:
    Ui::Widget *ui;
    QPoint p; //坐标的差值

    //起点坐标、终点坐标变量
    QPoint start, end;

    //小格子的宽度和高度
    int gridW, gridH;

    //定义一个二维数组保存黑白子的状态
    int chess[8][8];

    ChessStatus role; //角色

    QTimer mTimer; //定时器

    //倒计时
    int timeNum;
    QTimer leftTimer;

};

#endif // WIDGET_H
