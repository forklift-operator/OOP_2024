class Counter
{
protected:
    int initial;
    int total = 0;
    unsigned step;

public:
    Counter() : initial(0), step(1){};
    Counter(int init) : initial(init), step(1){};
    Counter(int init, unsigned st) : initial(init), step(st){};

    virtual void increment()
    {
        total += step;
    };

    int getTotal() const
    {
        return this->total;
    };

    unsigned getStep() const
    {
        return this->step;
    };
};

class TwowayCounter : public Counter
{
public:
    void decrement()
    {
        total -= step;
    };
};

class LimitedCounter : public Counter
{
private:
    int min, max;

public:
    LimitedCounter(int MAX) : max(MAX){};
    LimitedCounter(int MAX, int init) : max(MAX), Counter(init){};
    LimitedCounter(int MAX, int init, unsigned st) : max(MAX), Counter(init, st){};

    void increment()
    {
        if (total + step <= max)
        {
            total+=step;
        }
    };
};

class LimitedTwowayCounter
{
private:
    /* data */
public:
    LimitedTwowayCounter(/* args */);
    ~LimitedTwowayCounter();
};
