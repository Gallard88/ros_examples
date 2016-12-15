#include "CompassWidget.h"

#include <QPainter>
#include <QString>

#include <cmath>

CompassWidget::CompassWidget():
  Degrees_(0)
{

}

QSize CompassWidget::minimumSizeHint() const
{
  return QSize(200,200);
}

QSize CompassWidget::sizeHint() const
{
  return QSize(200,200);
}

void CompassWidget::drawSolidProngs(QPainter & p)
{
  QPoint prongs[3];
  // Draw Solid Prongs
  p.setPen(QColor(152,46,32));
  p.setBrush(QColor(152,46,32));
  prongs[0] = QPoint( 100, 100);

  prongs[1] = QPoint( 100,   0);
  prongs[2] = QPoint( 110, 100);
  p.drawPolygon( prongs, 3);

  prongs[1] = QPoint( 200, 100);
  prongs[2] = QPoint( 100, 110);
  p.drawPolygon( prongs, 3);

  prongs[1] = QPoint( 200, 100);
  prongs[2] = QPoint( 100, 110);
  p.drawPolygon( prongs, 3);

  prongs[1] = QPoint( 100, 200);
  prongs[2] = QPoint(  90, 100);
  p.drawPolygon( prongs, 3);

  prongs[1] = QPoint(   0, 100);
  prongs[2] = QPoint( 100,  90);
  p.drawPolygon( prongs, 3);

}

void CompassWidget::drawHollowProngs(QPainter & p)
{
  QPoint prongs[3];
  p.setPen(QColor(152,46,32));
  p.setBrush(QColor(255,255,255));

  prongs[0] = QPoint( 100, 100);

  prongs[1] = QPoint( 100,   0);
  prongs[2] = QPoint(  90, 100);
  p.drawPolygon( prongs, 3);

  prongs[1] = QPoint( 200, 100);
  prongs[2] = QPoint( 100,  90);
  p.drawPolygon( prongs, 3);

  prongs[1] = QPoint( 100, 200);
  prongs[2] = QPoint( 110, 100);
  p.drawPolygon( prongs, 3);

  prongs[1] = QPoint(   0, 100);
  prongs[2] = QPoint( 100, 110);
  p.drawPolygon( prongs, 3);
}

void CompassWidget::drawArrow(QPainter & p)
{
  QPoint points[3];
  p.setPen(QColor(0,0,255));
  p.setBrush(QColor(0,0,255));

  float radians = ( Degrees_ * 3.17 ) / 180.0;

  points[0] = QPoint( 100+75.0*std::cos(radians), 100-75.0*std::sin(radians));
  points[1] = QPoint( 100-25.0*std::cos(radians), 100+25.0*std::sin(radians));

  radians = (( Degrees_ + 135.0) * 3.17 ) / 180.0;
  points[2] = QPoint( 100+60.0*std::cos(radians), 100-60.0*std::sin(radians));

  p.drawPolygon( points, 3);

  p.setBrush(QColor(255,255,255));
  radians = (( Degrees_ - 135.0) * 3.17 ) / 180.0;
  points[2] = QPoint( 100+60.0*std::cos(radians), 100-60.0*std::sin(radians));
  p.drawPolygon( points, 3);
}

void CompassWidget::paintEvent(QPaintEvent *)
{
  QPainter painter(this);

  painter.setPen(QColor(0,0,0));
  painter.setBrush(QColor(255,255,255));
  painter.drawRect(0,0,199,199);

  painter.drawEllipse(1,1,198,198);
  painter.drawLine(0,99,198,99);
  painter.drawLine(99,0,99,198);

  painter.drawText(175, 190, QString::number( Degrees_));

  drawSolidProngs(painter);
  drawHollowProngs(painter);
  drawArrow(painter);
}

void CompassWidget::setBearing(int degrees)
{
  if ( Degrees_ != degrees ) {
    Degrees_ = degrees;
    update();
  }
}
