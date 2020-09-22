
#include "CalibrationDropdownBasic.h"
#include <QPropertyAnimation>
#include <QSlider>
#include <iostream>


CalibrationDropdownBasic::CalibrationDropdownBasic(QWidget *parent)
        : QWidget(parent),
          angle_label(new QLabel("angle")),
          angle_value_label(new QLabel()),
          rotation_label(new QLabel("rotation")),
          rotation_value_label(new QLabel()),
          angle_slider(new QSlider(Qt::Horizontal)),
          rotation_slider(new QSlider(Qt::Horizontal)) {

    // set slider properties
    auto f = this->angle_value_label;

    auto v = this->angle_slider;
    auto x = this->rotation_slider;
    QObject::connect(angle_slider, &QSlider::valueChanged, [f, x, v](int value) {
        f->setNum(value * 3);
    });
    angle_slider->setRange(0, 10);
    angle_slider->setValue(3);

    auto g = this->rotation_value_label;
    QObject::connect(rotation_slider, &QSlider::valueChanged, [g, x, v](int value) {
        g->setNum(value * 3);
    });
    rotation_slider->setRange(0, 10);
    rotation_slider->setValue(4);

    // right justify labels
    angle_label->setAlignment(Qt::AlignRight);
    rotation_label->setAlignment(Qt::AlignRight);

    sec = new Section("Basic", 100, this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(sec);
    layout->setMargin(0);

    auto *section_layout = new QGridLayout();

    section_layout->addWidget(angle_label, 0, 0);
    section_layout->addWidget(angle_slider, 0, 1);
    section_layout->addWidget(angle_value_label, 0, 2);

    section_layout->addWidget(rotation_label, 1, 0);
    section_layout->addWidget(rotation_slider, 1, 1);
    section_layout->addWidget(rotation_value_label, 1, 2);

    connect(angle_slider, QOverload<int>::of(&QSlider::valueChanged), this,
            &CalibrationDropdownBasic::angleSliderValueChanged);
    connect(rotation_slider, QOverload<int>::of(&QSlider::valueChanged), this,
            &CalibrationDropdownBasic::rotationSliderValueChanged);

    section_layout->setRowStretch(section_layout->rowCount(), 1);


    sec->setContentLayout(*section_layout);
}


// --------------------------------------------------------------------------------
//                          QCustomWidget methods
// --------------------------------------------------------------------------------

QString CalibrationDropdownBasic::name() const {
    return "CalibrationDropdownBasic";
}

QString CalibrationDropdownBasic::includeFile() const {
    return "CalibrationDropdownBasic.h";
}

QString CalibrationDropdownBasic::group() const {
    return tr("Containers");
}

QIcon CalibrationDropdownBasic::icon() const {
    return QIcon("icon.png");
}

QString CalibrationDropdownBasic::toolTip() const {
    return tr("Collapsible and expandable section");
}

QString CalibrationDropdownBasic::whatsThis() const {
    return tr("Contains basic calibration controls");
}

bool CalibrationDropdownBasic::isContainer() const {
    return true;
}

QWidget *CalibrationDropdownBasic::createWidget(QWidget *parent) {
    return new CalibrationDropdownBasic(parent);
}
