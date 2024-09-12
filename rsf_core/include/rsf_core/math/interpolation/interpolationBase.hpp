namespace rsf
{
    class InterpolationBase
    {
    public:
        InterpolationBase();

        void GetNextPoint();

    protected:
        double start_p;
        double end_p;

        double max_vec;
        double max_acc;
    };
}