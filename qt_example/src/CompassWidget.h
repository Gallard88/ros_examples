#ifndef COMPASSWIDGET_H
#define COMPASSWIDGET_H

#include <QWidget>

class CompassWidget: public QWidget
{
  Q_OBJECT

public:
    CompassWidget();

public slots:
    void setBearing(int degrees);

protected:
    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void paintEvent(QPaintEvent *event);

private:
    void drawSolidProngs(QPainter & p);
    void drawHollowProngs(QPainter & p);
    void drawArrow(QPainter & p);

    int Degrees_;

};

#endif // COMPASSWIDGET_H
