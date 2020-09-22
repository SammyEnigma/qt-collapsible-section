#include "ScanDropdownBasic.h"
#include <QPropertyAnimation>
#include <QSlider>
#include <iostream>


ScanDropdownBasic::ScanDropdownBasic(QWidget *parent)
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
    angle_slider->setValue(10);

    auto g = this->rotation_value_label;
    QObject::connect(rotation_slider, &QSlider::valueChanged, [g, x, v](int value) {
        g->setNum(value);
    });
    rotation_slider->setRange(0, 30);
    rotation_slider->setValue(10); // it's like bugged, need to set 3 before 4 displays
    rotation_slider->setValue(12);

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
            &ScanDropdownBasic::angleSliderValueChanged);
    connect(rotation_slider, QOverload<int>::of(&QSlider::valueChanged), this,
            &ScanDropdownBasic::rotationSliderValueChanged);

    section_layout->setRowStretch(section_layout->rowCount(), 1);


    sec->setContentLayout(*section_layout);
}


// --------------------------------------------------------------------------------
//                          QCustomWidget methods
// --------------------------------------------------------------------------------

QString ScanDropdownBasic::name() const {
    return "ScanDropdownBasic";
}

QString ScanDropdownBasic::includeFile() const {
    return "ScanDropdownBasic.h";
}

QString ScanDropdownBasic::group() const {
    return tr("Containers");
}

QIcon ScanDropdownBasic::icon() const {
    return QIcon("icon.png");
}

QString ScanDropdownBasic::toolTip() const {
    return tr("Collapsible and expandable section");
}

QString ScanDropdownBasic::whatsThis() const {
    return tr("Contains basic scan controls");
}

bool ScanDropdownBasic::isContainer() const {
    return true;
}

QWidget *ScanDropdownBasic::createWidget(QWidget *parent) {
    return new ScanDropdownBasic(parent);
}
