#ifndef QT_COLLAPSIBLE_SECTION_SCANDROPDOWNBASIC_H
#define QT_COLLAPSIBLE_SECTION_SCANDROPDOWNBASIC_H

#include "Section.h"
#include <QFrame>
#include <QGridLayout>
#include <QParallelAnimationGroup>
#include <QScrollArea>
#include <QToolButton>
#include <QWidget>
#include <QDesignerCustomWidgetInterface>
#include <QtDesigner>


class QDESIGNER_WIDGET_EXPORT ScanDropdownBasic : public QWidget, public QDesignerCustomWidgetInterface {
Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetInterface)
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QScanDropdownBasic")

private:

    QLabel *angle_label;
    QLabel *angle_value_label;
    QLabel *rotation_label;
    QLabel *rotation_value_label;

    QSlider *angle_slider;
    QSlider *rotation_slider;
    Section *sec;

signals:
    void angleSliderValueChanged(int x);
    void rotationSliderValueChanged(int x);

public:
    explicit ScanDropdownBasic(const QString &title = "", const int animationDuration = 100,
                                      QWidget *parent = 0);

    QString name() const;

    QString includeFile() const;

    QString group() const;

    QIcon icon() const;

    QString toolTip() const;

    QString whatsThis() const;

    bool isContainer() const;

    QWidget *createWidget(QWidget *parent);
};


#endif //QT_COLLAPSIBLE_SECTION_SCANDROPDOWNBASIC_H
