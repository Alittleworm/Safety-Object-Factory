#include<iostream>
#include<memory>
#include<string>
#include<mutex>
#include<map>
#include<functional>
#include "Mutex.h"
using namespace std;

class Mutex
{
public:
	Mutex()
	{
		mutex_.lock();
	}
	~Mutex()
	{
		mutex_.unlock();
	}

private:
	mutex mutex_;
	
};


class noncopyable
{
protected:
	noncopyable() {}
	~noncopyable() {}
private:  // emphasize the following members are private
	noncopyable(const noncopyable&);
	const noncopyable& operator=(const noncopyable&);
};

class Stock
{
public:
	Stock(string tkey) :key_(tkey){};
	string key()
	{
		return key_;
	}
private:
	string key_;
};

class StockFactory :public enable_shared_from_this<StockFactory>, noncopyable
{
public:
	shared_ptr<Stock> get(const string& key)
	{
		shared_ptr<Stock> pStock;
		MutexLockGuard lock(mutex_);
		weak_ptr<Stock>& wkStock = stocks_[key];
		pStock = wkStock.lock();
		if (!pStock)
		{
			pStock.reset(new Stock(key), 
				bind(&StockFactory::weakDeleteCallback, 
					weak_ptr<StockFactory>(shared_from_this()), std::placeholders::_1));
			wkStock = pStock;
		}
		return pStock;

	}
	static void weakDeleteCallback(weak_ptr<StockFactory> wkFactory,
		Stock* stock)
	{
		shared_ptr<StockFactory> factory(wkFactory.lock()); // 尝试提升
		if (factory) { // 如果 factory 还在，那就清理 stocks_
			factory->removeStock(stock);
		}
		delete stock; // sorry, I lied
	}
	void removeStock(Stock* stock)
	{
		if (stock) {
			MutexLockGuard lock(mutex_);
			stocks_.erase(stock->key());
		}
	}

private:
	MutexLock mutex_;
	std::map<string, weak_ptr<Stock>> stocks_;
};
