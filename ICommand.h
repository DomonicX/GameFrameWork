#ifndef ICOMMAND_H
#define ICOMMAND_H


class ICommand
{
public:
    ICommand() ;
    virtual ~ICommand();
    virtual void excute() = 0;

protected:

private:
};

#endif // ICOMMAND_H

