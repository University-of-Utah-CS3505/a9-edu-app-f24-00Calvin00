#ifndef INTROTOGUTHEALTHWIDGET_H
#define INTROTOGUTHEALTHWIDGET_H

#include <QWidget>

namespace Ui {
class IntroToGutHealthWidget;
}

/**
 * @class IntroToGutHealthWidget
 * @brief A widget that introduces users to the concept of gut health in an educational application.
 *
 * This widget provides an overview of gut health, highlighting its importance and role in overall well-being.
 * It serves as the entry point to learning about gut health, presenting introductory content in a user-friendly way.
 *
 * Responsibilities:
 * - Display introductory educational content about gut health.
 * - Allow navigation back to the main teaching widget.
 *
 * Usage:
 * - Include this widget as part of the educational application's teaching module.
 * - Connect the `backToTeachingWidgetButtonClicked` signal to handle navigation to the parent teaching widget.
 */
class IntroToGutHealthWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for IntroToGutHealthWidget.
     * @param parent The parent widget, or nullptr if there is no parent.
     *
     * Initializes the UI components and prepares the widget for user interaction.
     */
    explicit IntroToGutHealthWidget(QWidget *parent = nullptr);

    /**
     * @brief Destructor for IntroToGutHealthWidget.
     *
     * Cleans up dynamically allocated resources, ensuring proper memory management.
     */
    ~IntroToGutHealthWidget();

signals:
    /**
     * @brief Emitted when the "Back to Teaching" button is clicked.
     *
     * Allows navigation from the introduction widget back to the main teaching widget.
     */
    void backToTeachingWidgetButtonClicked();

private:
    Ui::IntroToGutHealthWidget *ui; ///< Pointer to the UI elements for the widget.
};

#endif // INTROTOGUTHEALTHWIDGET_H
