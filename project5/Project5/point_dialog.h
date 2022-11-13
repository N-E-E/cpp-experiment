#pragma once

#include <QDialog>
#include "ui_point_dialog.h"

class point_dialog : public QDialog
{
	Q_OBJECT

public:
	point_dialog(QWidget *parent = nullptr);
	~point_dialog();

private:
	Ui::point_dialogClass ui;
};
