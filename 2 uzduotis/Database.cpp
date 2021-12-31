#include "Database.h"
Database::Database(int cnt): Item( cnt,"Tb", "Database") {
    setPrice(10, 5);
}
Database::Database(): Item( 0,"Tb", "Database") {
    setPrice(10,5);
    int n=1000+rand()% 5001;
    increaseCount(n);
}
