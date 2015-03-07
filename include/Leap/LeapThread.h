#include "Leap.h"

namespace Leap {

class LeapThread;

/**
 * @author Matej Marconak
 * @brief The LeapThread class
 * @brief Thread for processing LeapMotion data
 */
class LeapThread : public QThread
{
    Q_OBJECT

public:
    LeapThread( QObject* parent=NULL );
    ~LeapThread( void );
    void run();

};
}
