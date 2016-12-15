#include "LedWidget.h"

LedWidget::LedWidget():
  Checked_(false),
  Color_(QColor(255,0,0))
{
}

LedWidget::LedWidget(QColor color):
  Checked_(false), Color_(color)
{
}

bool LedWidget::isChecked()
{
  return Checked_;
}

void LedWidget::setChecked(bool check)
{
  if ( Checked_ != check ) {
    Checked_ = check;
    this->update();
  }
}

QSize LedWidget::minimumSizeHint() const
{
  return QSize(20,20);
}

QSize LedWidget::sizeHint() const
{
  return QSize(20,20);
}

void LedWidget::paintEvent(QPaintEvent *)
{
  QPainter painter(this);

  painter.setPen(QColor(0,0,0));
  if ( Checked_ == true ) {
    painter.setBrush(Color_);
  }
  painter.drawEllipse(QRect(0,0, 19, 19));
}

