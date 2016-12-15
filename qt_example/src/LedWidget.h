#ifndef LEDWIDGET_H
#define LEDWIDGET_H

#include <QWidget>
#include <QPainter>

class LedWidget: public QWidget
{
  Q_OBJECT

public:
    LedWidget();
    LedWidget(QColor color);

    bool isChecked();
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

public slots:
    void setChecked(bool check);

signals:

protected:
  void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
  bool Checked_;
  QColor Color_;
};

#endif // LEDWIDGET_H
