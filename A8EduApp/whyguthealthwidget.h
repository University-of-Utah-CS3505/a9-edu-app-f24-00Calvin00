#ifndef WHYGUTHEALTHWIDGET_H
#define WHYGUTHEALTHWIDGET_H

#include <QWidget>

namespace Ui {
class WhyGutHealthWidget;
}

/**
 * @class WhyGutHealthWidget
 * @brief A widget for presenting information about the importance of gut health.
 *
 * This class is part of an educational application designed to teach users about gut health.
 * The widget displays content explaining the consequences of neglecting gut health and provides
 * a way for users to navigate back to the teaching section of the application.
 *
 * Responsibilities:
 * - Display educational content about gut health.
 * - Provide a signal for navigating back to the teaching widget.
 *
 * Usage:
 * - Instantiate this class as part of a larger application.
 * - Connect the `backToTeachingWidgetButtonClicked` signal to handle navigation logic.
 */
class WhyGutHealthWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for WhyGutHealthWidget.
     * @param parent The parent widget, or nullptr if there is no parent.
     *
     * Initializes the widget and sets up the UI components.
     */
    explicit WhyGutHealthWidget(QWidget *parent = nullptr);

    /**
     * @brief Destructor for WhyGutHealthWidget.
     *
     * Cleans up dynamically allocated resources.
     */
    ~WhyGutHealthWidget();

signals:
    /**
     * @brief Emitted when the "Back" button is clicked.
     *
     * This signal allows navigation from the current widget back to the teaching widget.
     */
    void backToTeachingWidgetButtonClicked();

private:
    Ui::WhyGutHealthWidget *ui; ///< Pointer to the UI elements for the widget.
};

#endif // WHYGUTHEALTHWIDGET_H
