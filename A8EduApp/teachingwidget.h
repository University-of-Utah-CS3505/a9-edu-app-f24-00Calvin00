#ifndef TEACHINGWIDGET_H
#define TEACHINGWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <introtoguthealthwidget.h>
#include <whyguthealthwidget.h>
#include <howtostayhealthywidget.h>

namespace Ui {
class TeachingWidget;
}

/**
 * @class TeachingWidget
 * @brief A central widget for teaching users about gut health in an educational application.
 *
 * This class acts as a container for different sub-widgets, each presenting specific educational
 * content about gut health. It manages navigation between the introduction, the importance of gut health,
 * and tips for maintaining gut health. Additionally, it provides a signal to return to the application's
 * starting point.
 *
 * Responsibilities:
 * - Display educational content via sub-widgets.
 * - Provide navigation between sub-widgets and back to the start of the application.
 *
 * Usage:
 * - Instantiate this widget in the main application window.
 * - Connect the signals to handle user navigation between sections.
 */
class TeachingWidget : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Constructor for TeachingWidget.
     * @param parent The parent widget, or nullptr if there is no parent.
     *
     * Initializes the widget, sets up UI components, and prepares sub-widgets for navigation.
     */
    explicit TeachingWidget(QWidget *parent = nullptr);

    /**
     * @brief Destructor for TeachingWidget.
     *
     * Cleans up dynamically allocated resources, including sub-widgets.
     */
    ~TeachingWidget();

private:
    Ui::TeachingWidget *ui;
    IntroToGutHealthWidget *introToGutHealthWidget;
    WhyGutHealthWidget *whyGutHealthWidget;
    HowToStayHealthyWidget *howToStayHealthyWidget;

signals:
    /**
     * @brief Emitted when the "Introduction to Gut Health" button is clicked.
     *
     * Allows navigation to the `IntroToGutHealthWidget` from the main teaching widget.
     */
    void introToGutButtonClicked();

    /**
     * @brief Emitted when the "Why Gut Health?" button is clicked.
     *
     * Allows navigation to the `WhyGutHealthWidget` from the main teaching widget.
     */
    void whyGutHealthButtonClicked();

    /**
     * @brief Emitted when the "How to Stay Healthy" button is clicked.
     *
     * Allows navigation to the `HowToStayHealthyWidget` from the main teaching widget.
     */
    void howToStayHealthyButtonClicked();

    /**
     * @brief Emitted when the "Back to Start" button is clicked.
     *
     * Enables the user to return to the starting screen of the application.
     */
    void backToStartButtonClicked();

private:
    Ui::TeachingWidget *ui; ///< Pointer to the UI elements for the widget.

    IntroToGutHealthWidget *introToGutHealthWidget; ///< Widget for the introduction to gut health section.
    WhyGutHealthWidget *whyGutHealthWidget; ///< Widget for explaining the importance of gut health.
    HowToStayHealthyWidget *howToStayHealthyWidget; ///< Widget for tips on maintaining gut health.

    // Uncomment if implementing image setup functionality
    // /**
    //  * @brief Sets up the view for displaying images.
    //  *
    //  * Prepares a QGraphicsView or other UI element for displaying visual content.
    //  */
    // void setupImageView();
};

#endif // TEACHINGWIDGET_H
