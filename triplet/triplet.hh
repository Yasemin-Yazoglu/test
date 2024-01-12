#pragma once

template <typename T1, typename T2, typename T3>
class Triplet {
    private:
        T1 first_;
        T2 second_;
        T3 third_;

    public:
        Triplet(T1 first, T2 second, T3 third) : first_(first), second_(second), third_(third) {}
        // Getter Methoden
        T1 first() const { return first_; }
        T2 second() const { return second_; }
        T3 third() const { return third_; }

        // Setter Methoden
        void setFirst(T1 value) { first_ = value; }
        void setSecond(T2 value) { second_ = value; }
        void setThird(T3 value) { third_ = value; }
};
