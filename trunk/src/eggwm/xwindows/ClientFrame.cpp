/**
 * @file /src/eggwm/xwindows/ClientFrame.cpp
 *
 * @~spanish
 * Este archivo es parte del proyecto Egg Window Manager, usted puede
 * redistribuirlo y/o modificarlo bajo los téminos de la licencia GNU GPL v3.
 *
 * @~english
 * This file is part of the Egg Window Manager project, you can redistribute it
 * and/or modify it under the terms of the GNU GPL v3.
 *
 * @class  EggWM
 * @author José Expósito
 */
#include "ClientFrame.h"

// ************************************************************************** //
// **********             STATIC METHODS AND VARIABLES             ********** //
// ************************************************************************** //

const int ClientFrame::MOVE          = (1<<0);
const int ClientFrame::TOP_BORDER    = (1<<1);
const int ClientFrame::BOTTOM_BORDER = (1<<2);
const int ClientFrame::LEFT_BORDER   = (1<<3);
const int ClientFrame::RIGHT_BORDER  = (1<<4);

const int ClientFrame::CORNER_SIZE   = 40;


// ************************************************************************** //
// **********              CONSTRUCTORS AND DESTRUCTOR             ********** //
// ************************************************************************** //

ClientFrame::ClientFrame(bool showIcon, bool showMaxButton, QWidget* parent)
        : QWidget(parent) {
    Config* cfg = Config::getInstance();

    // Inicializamos los atributos
    this->mouseMask = 0;

    this->titlebar       = new QLabel(this);
    this->title          = new QLabel(this);
    this->topBorder      = new QLabel(this);
    this->bottomBorder   = new QLabel(this);
    this->leftBorder     = new QLabel(this);
    this->rightBorder    = new QLabel(this);
    this->minimizeButton = new QPushButton(this);
    this->maximizeButton = new QPushButton(this);
    this->exitButton     = new QPushButton(this);
    this->icon           = new QLabel(this);

    // Hacemos que las imágenes se ajusten a sus contenedores
    this->titlebar->setScaledContents(true);
    this->topBorder->setScaledContents(true);
    this->bottomBorder->setScaledContents(true);
    this->leftBorder->setScaledContents(true);
    this->rightBorder->setScaledContents(true);
    this->icon->setScaledContents(true);

    // Ponemos los cursores para los bordes
    this->topBorder->setCursor(Qt::SizeVerCursor);
    this->bottomBorder->setCursor(Qt::SizeVerCursor);
    this->leftBorder->setCursor(Qt::SizeHorCursor);
    this->rightBorder->setCursor(Qt::SizeHorCursor);

    // Establecemos el nombre de los distintos elementos configurables desde el
    // archivo de configuración "style.qss"
    this->setObjectName("ClientFrame");
    this->titlebar->setObjectName("titlebar");
    this->title->setObjectName("title");
    this->topBorder->setObjectName("topBorder");
    this->bottomBorder->setObjectName("bottomBorder");
    this->rightBorder->setObjectName("rightBorder");
    this->leftBorder->setObjectName("leftBorder");
    this->minimizeButton->setObjectName("minimizeButton");
    this->maximizeButton->setObjectName("maximizeButton");
    this->exitButton->setObjectName("exitButton");
    this->icon->setObjectName("icon");

    // Mostramos o no los distintos elementos según corresponda
    this->icon->setVisible(showIcon);
    this->maximizeButton->setVisible(showMaxButton);

    // Lanzamos señales cuando se pulsa un botón
    connect(this->minimizeButton, SIGNAL(clicked()), this,
            SIGNAL(minimizedFrame()));
    connect(this->maximizeButton, SIGNAL(clicked()), this,
            SIGNAL(maximizedFrame()));
    connect(this->exitButton, SIGNAL(clicked()),this, SIGNAL(closedFrame()));

    // Aplicamos el estilo a la ventana
    this->setStyleSheet(cfg->getStyle());

    // Ajustamos el tamaño de los distintos elementos
    this->title->resize(this->title->width(), cfg->getTitlebarWidth()
            + cfg->getTopBorderWidth());
    this->minimizeButton->resize(this->minimizeButton->iconSize());
    this->maximizeButton->resize(this->maximizeButton->iconSize());
    this->exitButton->resize(this->exitButton->iconSize());
    this->icon->resize(cfg->getIconSize(), cfg->getIconSize());

    // Establecemos la alineación de los elementos de la barra de título
    this->setVerticalAling(this->minimizeButton, cfg->getMinimizeButtonAling());
    this->setVerticalAling(this->maximizeButton, cfg->getMaximizeButtonAling());
    this->setVerticalAling(this->exitButton, cfg->getExitButtonAling());
    this->setVerticalAling(this->title, Config::TOP);
    this->setVerticalAling(this->icon, Config::CENTER);
}

ClientFrame::~ClientFrame() {
    delete this->titlebar;
    delete this->title;
    delete this->topBorder;
    delete this->bottomBorder;
    delete this->leftBorder;
    delete this->rightBorder;
    delete this->minimizeButton;
    delete this->maximizeButton;
    delete this->exitButton;
    delete this->icon;
}


// ************************************************************************** //
// **********                    PRIVATE METHODS                   ********** //
// ************************************************************************** //

void ClientFrame::setVerticalAling(QWidget* widget, Config::Aling aling) {
    Config* cfg = Config::getInstance();
    int topWidth =  cfg->getTitlebarWidth() + cfg->getTopBorderWidth();

    int y;
    switch(aling) {
    case Config::TOP:
        y = 0;
        break;
    case Config::CENTER:
        y = topWidth/2 - widget->width()/2;
        break;
    case Config::BOTTOM:
        y = topWidth - widget->width();
        break;
    default:
        y = 0;
        break;
    }

    widget->move(widget->x(), y);
}

void ClientFrame::reorganizeFrame() {
    Config* cfg = Config::getInstance();

    // Bara de título
    this->titlebar->resize(this->width(), cfg->getTitlebarWidth());
    this->titlebar->move(cfg->getLeftBorderWidth(),
            cfg->getTopBorderWidth());

    // Título
    this->title->adjustSize();
    this->title->resize(this->title->width(), cfg->getTitlebarWidth()
            + cfg->getTopBorderWidth());

    // Borde izquierdo
    this->leftBorder->resize(cfg->getLeftBorderWidth(),
            this->height() - cfg->getTopBorderWidth()
            - cfg->getBottomBorderWidth());
    this->leftBorder->move(0, cfg->getTopBorderWidth());

    // Borde derecho
    this->rightBorder->resize(cfg->getRightBorderWidth(),
            this->height() - cfg->getTopBorderWidth());
    this->rightBorder->move(this->width() - cfg->getRightBorderWidth(),
            cfg->getTopBorderWidth());

    // Border superior
    this->topBorder->resize(this->width(), cfg->getBottomBorderWidth());
    this->topBorder->move(0, 0);

    // Borde inferior
    this->bottomBorder->resize(this->width(), cfg->getBottomBorderWidth());
    this->bottomBorder->move(0, this->height()-cfg->getBottomBorderWidth());

    //--------------------------------------------------------------------------

    // Metemos los distintos elementos de la barra de título en los QHash
    QHash<int, QWidget*> left, center, right;

    QPair<Config::Aling, int> minimize = cfg->getMinimizeButtonPos();
    QPair<Config::Aling, int> maximize = cfg->getMaximizeButtonPos();
    QPair<Config::Aling, int> exit     = cfg->getExitButtonPos();
    QPair<Config::Aling, int> title    = cfg->getTitlePos();
    QPair<Config::Aling, int> icon     = cfg->getIconPos();

    this->placeInHash(minimize, this->minimizeButton, &left, &center, &right);
    if(this->maximizeButton->isVisible())
        this->placeInHash(maximize,this->maximizeButton,&left,&center,&right);
    this->placeInHash(exit, this->exitButton, &left, &center, &right);
    this->placeInHash(title, this->title, &left, &center, &right);
    if(this->icon->isVisible())
        this->placeInHash(icon, this->icon, &left, &center, &right);

    // Colocamos los elementos dentro de la barra de título
    this->placeItemsInTitlebar(&left, &center, &right);
}

void ClientFrame::placeInHash(const QPair<Config::Aling, int>& ip,
        QWidget* widget,
        QHash<int, QWidget*>* left,
        QHash<int, QWidget*>* center,
        QHash<int, QWidget*>* right) const {
    if(ip.first == Config::LEFT) {
        left->insert(ip.second, widget);
    } else if(ip.first == Config::CENTER) {
        center->insert(ip.second, widget);
    } else {
        right->insert(ip.second, widget);
    }
}

void ClientFrame::placeItemsInTitlebar(QHash<int, QWidget*>* left,
        QHash<int, QWidget*>* center, QHash<int, QWidget*>* right) {
    Config* cfg  = Config::getInstance();
    QHash<int, QWidget*>::iterator i;

    // Colocamos los elementos del área izquierda
    int leftMargin = cfg->getLeftBorderWidth() + 2;
    for (i=left->begin(); i!=left->end(); i++) {
        QWidget* w = i.value();
        w->move(leftMargin, w->y());
        leftMargin += w->width();
    }

    // Colocamos los elementos del área derecha
    int rightMargin = this->width() - cfg->getRightBorderWidth() - 2;
    for (i=right->end()-1; i!=right->begin()-1; i--) {
        QWidget* w = i.value();
        rightMargin -= w->width();
        w->move(rightMargin, w->y());
    }

    // Colocamos los elementos del centro
    int centralAreaSize = rightMargin - leftMargin;

    int centralItemsSize = 0;
    for (i=center->begin(); i!=center->end(); i++) {
        QWidget* w = i.value();
        centralItemsSize += w->width();
    }

    int centralMargin;
    if(centralAreaSize > centralItemsSize) {
        centralMargin = leftMargin + (centralAreaSize/2 - centralItemsSize/2);
    } else {
        centralMargin = leftMargin + 5;
    }

    for (i=center->begin(); i!=center->end(); i++) {
        QWidget* w = i.value();
        w->move(centralMargin, w->y());
        centralMargin += w->width();
    }
}

//------------------------------------------------------------------------------

bool ClientFrame::isClicked(QPoint clickPosition, const QLabel* label) const {
    if(clickPosition.x() >= label->x()
            && clickPosition.x() <= label->x() + label->width()
            && clickPosition.y() >= label->y()
            && clickPosition.y() <= label->y() + label->height())
        return true;
    else
        return false;
}


// ************************************************************************** //
// **********                   PROTECTED METHODS                  ********** //
// ************************************************************************** //

void ClientFrame::mousePressEvent(QMouseEvent* event) {
    this->clickPosition =  event->pos();

    // Barra de título
    if(this->isClicked(this->clickPosition, this->titlebar))
        this->mouseMask |= MOVE;

    // Borde superior
    else if(this->isClicked(event->pos(), this->topBorder)) {
        this->mouseMask |= TOP_BORDER;

        if(this->clickPosition.x() < CORNER_SIZE)
            this->mouseMask |= LEFT_BORDER;

        if(this->clickPosition.x() > this->width() - CORNER_SIZE)
            this->mouseMask |= RIGHT_BORDER;

    // Borde inferior
    } else if(this->isClicked(event->pos(), this->bottomBorder)) {
        this->mouseMask |= BOTTOM_BORDER;

        if(this->clickPosition.x() < CORNER_SIZE)
            this->mouseMask |= LEFT_BORDER;

        if(this->clickPosition.x() > this->width() - CORNER_SIZE)
            this->mouseMask |= RIGHT_BORDER;

    // Borde izquierdo
    } else if(this->isClicked(event->pos(), this->leftBorder)) {
        this->mouseMask |= LEFT_BORDER;

        if(this->clickPosition.y() < CORNER_SIZE)
            this->mouseMask |= TOP_BORDER;

        if(this->clickPosition.y() > this->height() - CORNER_SIZE)
            this->mouseMask |= BOTTOM_BORDER;

    // Borde derecho
    } else if(this->isClicked(event->pos(), this->rightBorder)) {
        this->mouseMask |= RIGHT_BORDER;

        if(this->clickPosition.y() < CORNER_SIZE)
            this->mouseMask |= TOP_BORDER;

        if(this->clickPosition.y() > this->height() - CORNER_SIZE)
            this->mouseMask |= BOTTOM_BORDER;
    }
}

void ClientFrame::mouseMoveEvent(QMouseEvent* event) {
    // Si se quiere desplazar la ventana
    if(this->mouseMask & MOVE)
        this->move(event->globalPos() - this->clickPosition);

    // Si se quiere estirar el borde superior
    if(this->mouseMask & TOP_BORDER) {
        int oldHeight = this->getHeight();
        if(emit this->resizedFrame(0, this->y() - event->globalPos().y()))
            this->move(this->x(), this->y() - (this->getHeight() - oldHeight));

    // Si se quiere estirar el borde inferior
    } if(this->mouseMask & BOTTOM_BORDER)
        emit this->resizedFrame(0, event->globalPos().y() - this->y()
                - this->height());

    // Si se quiere estirar el borde izquierdo
    if(this->mouseMask & LEFT_BORDER) {
        int oldWidth = this->getWidth();
        if(emit this->resizedFrame(this->x() - event->globalPos().x(), 0))
            this->move(this->x() - (this->getWidth() - oldWidth), this->y());

    // Si se quiere estirar el borde derecho
    } if(this->mouseMask & RIGHT_BORDER)
        emit this->resizedFrame(event->globalPos().x() - this->x()
                - this->width(), 0);
}

void ClientFrame::mouseReleaseEvent(QMouseEvent* /*event*/) {
    this->mouseMask = 0;
}


// ************************************************************************** //
// **********                      GET/SET/IS                      ********** //
// ************************************************************************** //

void ClientFrame::setVisible(bool visible) {
    QWidget::setVisible(visible);
    if(visible) {
        this->reorganizeFrame();
    }
}

//------------------------------------------------------------------------------

void ClientFrame::setX(int x) {
    this->move(x, this->y());
}

void ClientFrame::setY(int y) {
    this->move(this->x(), y);
}

void ClientFrame::setWidth(unsigned int width) {
    this->resize(width, this->height());
    if(this->isVisible())
        this->reorganizeFrame();
}

void ClientFrame::setHeight(unsigned int height) {
    this->resize(this->width(), height);
    if(this->isVisible())
        this->reorganizeFrame();
}

unsigned int ClientFrame::getWidth() const {
    return this->width();
}

unsigned int ClientFrame::getHeight() const {
    return this->height();
}

//------------------------------------------------------------------------------

void ClientFrame::setTitle(const QString& title) {
    this->title->setText(title);
    if(this->isVisible())
        this->reorganizeFrame();
}

void ClientFrame::setIconPixmap(const QPixmap& pixmap) {
    if(!pixmap.isNull())
        this->icon->setPixmap(pixmap);
}
