#include "CollapsibleSection.h"

CollapsibleSection::CollapsibleSection(QWidget *parent)
    : QWidget(parent), isExpanded(false), sectionHeight(200)
{
    toggleButton = new QPushButton("Expand", this);
    titleLabel = new QLabel(this);
    contentWidget = new QWidget(this);

    // Layout for the section
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(toggleButton);
    mainLayout->addWidget(contentWidget);

    // Set the initial collapsed state for the content widget
    contentWidget->setFixedHeight(0);
    contentWidget->setVisible(false);

    // Set up the toggle animation
    animation = new QPropertyAnimation(contentWidget, "geometry");
    animation->setDuration(300);

    // Set the button's toggle slot
    connect(toggleButton, &QPushButton::clicked, this, &CollapsibleSection::toggleSection);
}

void CollapsibleSection::setSectionTitle(const QString &title)
{
    titleLabel->setText(title);
}

void CollapsibleSection::setContentWidget(QWidget *widget)
{
    // Clear previous content and set new content widget
    QLayoutItem *item;
    while ((item = mainLayout->takeAt(2)) != nullptr) {
        delete item->widget();
    }
    mainLayout->addWidget(widget);
    contentWidget = widget;
}

void CollapsibleSection::setInitialHeight(int height)
{
    sectionHeight = height;
}

void CollapsibleSection::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    int newWidth = event->size().width();
    contentWidget->setFixedWidth(newWidth);
}

void CollapsibleSection::toggleSection()
{
    if (isExpanded) {
        // Collapse the section
        animation->setStartValue(contentWidget->geometry());
        animation->setEndValue(QRect(contentWidget->x(), contentWidget->y(), contentWidget->width(), 0));
        contentWidget->setVisible(false);
        toggleButton->setText("Expand");
    } else {
        // Expand the section
        contentWidget->setVisible(true);
        animation->setStartValue(contentWidget->geometry());
        animation->setEndValue(QRect(contentWidget->x(), contentWidget->y(), contentWidget->width(), sectionHeight));
        toggleButton->setText("Collapse");
    }
    isExpanded = !isExpanded;
    animation->start();
}
