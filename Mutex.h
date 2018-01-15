#include <iostream>
#include <pthread.h>

using namespace std;

class MutexLock
{
public:
	MutexLock()
	{
		pthread_mutex_init(&mutex_, NULL);
	}

	~MutexLock()
	{
		pthread_mutex_destroy(&mutex_);
	}

	void Lock()
	{
		pthread_mutex_lock(&mutex_);
	}

	void Unlock()
	{
		pthread_mutex_unlock(&mutex_);
	}

private:
	MutexLock(const MutexLock&);
	MutexLock& operator=(const MutexLock&);
	pthread_mutex_t mutex_;
};

class MutexLockGuard
{
public:
	explicit MutexLockGuard(MutexLock& mutex) : mutex_(mutex)
	{
		mutex_.Lock();
	}

	~MutexLockGuard()
	{
		mutex_.Unlock();
	}

private:
	MutexLockGuard(const MutexLockGuard&);
	MutexLockGuard& operator=(const MutexLockGuard&);

	MutexLock& mutex_;
};

class Foo
{
public:
	void print()
	{
		MutexLockGuard lock(mutex_);
		cout << "Hello" << endl;
	}

private:
	MutexLock mutex_;
};