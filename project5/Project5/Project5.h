#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Project5.h"

class Project5 : public QMainWindow
{
    Q_OBJECT

public:
    Project5(QWidget *parent = nullptr);
    ~Project5();

private:
    Ui::Project5Class ui;
    // 加载地图
    void load_map();
    // 关闭窗口
    void close_window();
    // 计算最小转乘
    void min_convert();
    // 计算最短距离
    void min_dist();
};
