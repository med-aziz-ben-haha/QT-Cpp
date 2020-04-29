#ifndef GLOBAL_H
#define GLOBAL_H
#include <QtGlobal>

// ALL THE GLOBAL DECLARATIONS

// don't use #include <QString> here, instead do this:

QT_BEGIN_NAMESPACE
class QString;
QT_END_NAMESPACE

// that way you aren't compiling QString into every header file you put this in...
// aka faster build times.

#define MAGIC_NUM 42

extern QString tmp;
extern QString sel_emp;
extern QString name;
extern QString sel_cong;
extern QString sel_cong_rh;
extern  qreal count;
extern  qreal login_times;

#endif // GLOBAL_H
