//
// Created by sam on 2/11/18.
//

#ifndef OTHELLO_MATRIXELEMENT_H
#define OTHELLO_MATRIXELEMENT_H


#include <QtWidgets/QGraphicsItem>
#include <QtGui/QMouseEvent>
#include <Headers/GameWindow.h>
class GameWindow;
class MatrixElement: public QObject,public QGraphicsItem {
Q_OBJECT
public:
    MatrixElement(GameWindow *);
    bool isUsable;
    int elementMode,xPos,yPos;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
signals:
    void clickedOn(int,int);
protected:
    void advance(int step) override;
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QGraphicsSceneMouseEvent *);

private:
    GameWindow *myParrent;
};


#endif //OTHELLO_MATRIXELEMENT_H
