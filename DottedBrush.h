//
// Created by Saraf Ray on 11/16/17.
//

#ifndef THE_STATISTICS_DOTTEDBRUSH_H
#define THE_STATISTICS_DOTTEDBRUSH_H


class DottedBrush : public Brush {
private:
    int dottedSpeed;
public:
    DottedBrush();

    int getDottedSpeed() const;
    void setDottedSpeed(int speedIn);

};





#endif //THE_STATISTICS_DOTTEDBRUSH_H
