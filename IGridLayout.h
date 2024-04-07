#ifndef IGRIDLAYOUT_H
#define IGRIDLAYOUT_H

#include <Vector2D.h>
class IGridLayout
{
    public:
        IGridLayout();
        virtual ~IGridLayout();
GetCell(int numpy);

    protected:

    private:
        int Column,row,alignFlag;
        rectangle _r;
        vec2f _o;

};


class GridLayoutComboBox : public IGridLayout
{
    public:
      GridLayoutComboBox();
        virtual ~GridLayoutComboBox ();

    protected:

    private:
};


#endif // IGRIDLAYOUT_H
