#pragma once
#include <iostream>


using namespace std;




template <class T>
class Range;

template <class T>
ostream& operator <<(ostream&, const Range<T>&);


template <class T>
class Range {
private:
	T start;
	T end;
	T step;

public:
	Range(T start, T end) : start(start), end(end), step(1) {}
	Range(T start, T end, T step) : start(start), end(end), step(step) {}
	Range noStep(Range<T>&);
	Range yesStep(Range<T>&);
	int length();
	T sum();
	T average();
	T max();
	T min();
	friend ostream& operator<< <>(ostream&, const Range<T>&);
};


template <class T>
Range<T> Range<T>::noStep(Range<T>& r) {
	if (start <= end){
		for (T i = r.start; i <= r.end; i++) {
			cout << i << " " << endl;
		}
	}
	else {
		for (T i = r.start; i >= r.end; i -= step) {
			cout << i << " " << endl;
		}
	}
	cout << endl;

}

template <class T>
Range<T> Range <T>::yesStep(Range<T>& r) {
	if (start <= end){
		for (T i = r.start; i <= r.end; i += r.step) {
			cout << i << " " << endl;
		}
	}
	else {
		for (T i = r.start; i >= r.end; i += r.step) {
			cout << i << " " << endl;
		}
	}
	cout << endl;

}

template<class T>
int Range<T>::length() {
	int length = (((abs(end - start)) / abs(step)) + 1);
	return length;
}

template <class T>
T Range <T>::sum() {
	T sum = 0;
	if (step > 0) {
		for (T i = start; i <= end; i += step) {
			sum += i;
		}

	}
	else {
		for (T i = start; i >= end; i += step) {
			sum += i;
		}
	}
	return sum;

}

template <class T>
T Range<T>::average() {
	T len = length();
	T total = sum();
	return total / len;
}

template <class T>
T Range <T>::min() {
	T min;
	if (step > 0) {
		return start;

	}
	else {
		T lastValue = start;
		while (lastValue + step >= end) {
			lastValue += step;
		}
		return lastValue;

	}
}

template <class T>
T Range<T>::max() {
	T max;
	if (step > 0) {
		T lastValue = start;
		while (lastValue + step <= end) {
			lastValue += step;
		}
		return lastValue;

	}
	else {
		return start;
	}

}

template <class T>
ostream& operator<<(ostream& out, const Range<T>& r) {
	if (r.step > 0) {
		for (T i = r.start; i <= r.end; i += r.step) {
			if (i != r.start) {
				out << ", ";
			}
			out << i;
		}

	}
	else {
		for (T i = r.start; i >= r.end; i += r.step) {
			if (i != r.start) {
				out << ", ";
			}
			out << i;
		}
	}
	out << endl;
	return out;
}