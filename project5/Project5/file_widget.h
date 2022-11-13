#pragma once

#include <QWidget>
#include "ui_file_widget.h"

class file_widget : public QWidget
{
	Q_OBJECT

public:
	file_widget(QWidget *parent = nullptr);
	~file_widget();

private:
	Ui::file_widgetClass ui;
	// ��ȡվ����Ϣ�ļ�
	void stop_input();
	// ��ȡ·����Ϣ�ļ�
	void line_input();
	// ���ȷ���鿴�ļ�û�����Ⲣ�ҹرմ���
	void check_file();

};
