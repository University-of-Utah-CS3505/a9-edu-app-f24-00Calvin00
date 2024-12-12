#ifndef HOWTOSTAYHEALTHYWIDGET_H
#define HOWTOSTAYHEALTHYWIDGET_H

#include <QWidget>

namespace Ui {
class HowToStayHealthyWidget;
}

/**
 * @class HowToStayHealthyWidget
 * @brief A widget that educates users on maintaining gut health through practical advice and tips.
 *
 * This widget focuses on teaching users actionable strategies for sustaining a healthy gut.
 * It is part of the educational module and provides interactive or informational content on gut health maintenance.
 *
 * Responsibilities:
 * - Display educational content about maintaining gut health.
 * - Offer actionable tips and guidelines for promoting gut health.
 * - Enable navigation back to the main teaching widget.
 *
 * Usage:
 * - Integrate this widget into the teaching section of the educational application.
 * - Utilize the `backToTeachingWidgetButtonClicked` signal to handle navigation to the parent teaching widget.
 */
class HowToStayHealthyWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for HowToStayHealthyWidget.
     * @param parent The parent widget, or nullptr if there is no parent.
     *
     * Sets up the UI components and prepares the widget for use.
     */
    explicit HowToStayHealthyWidget(QWidget *parent = nullptr);

    /**
     * @brief Destructor for HowToStayHealthyWidget.
     *
     * Ensures proper cleanup of dynamically allocated resources.
     */
    ~HowToStayHealthyWidget();

signals:
    /**
     * @brief Emitted when the "Back to Teaching" button is clicked.
     *
     * Facilitates navigation from the "How to Stay Healthy" widget back to the main teaching widget.
     */
    void backToTeachingWidgetButtonClicked();

private:
    Ui::HowToStayHealthyWidget *ui; ///< Pointer to the UI elements for this widget.
};

#endif // HOWTOSTAYHEALTHYWIDGET_H
