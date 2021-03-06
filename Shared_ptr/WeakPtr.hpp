#pragma once

#include <iostream>
#include "ControlBlock.hpp"
#include "SharedPtr.hpp"

namespace scr {
template <typename T>
class SharedPtr;
}  // namespace scr

namespace scr {
template <typename T>
class WeakPtr {
public:
    WeakPtr() noexcept = default;
    WeakPtr(const WeakPtr& ptr) noexcept;
    WeakPtr(const scr::SharedPtr<T>& ptr) noexcept;
    WeakPtr(WeakPtr&& ptr) noexcept;
    ~WeakPtr();

    WeakPtr& operator=(const WeakPtr& ptr) noexcept;
    WeakPtr& operator=(const scr::SharedPtr<T>& ptr) noexcept;
    WeakPtr& operator=(WeakPtr&& ptr) noexcept;

    size_t use_count() const noexcept;
    bool expired() const noexcept { return use_count() == 0; }
    void reset() noexcept;
    scr::SharedPtr<T> lock() const noexcept;

private:
    template <typename>
    friend class SharedPtr;

    void deleteResources();

    T* ptr_ = nullptr;
    ControlBlock<T>* cb_ = nullptr;
};

template <typename T>
WeakPtr<T>::WeakPtr(const WeakPtr& ptr) noexcept
    : ptr_(ptr.ptr_), cb_(ptr.cb_) {
    cb_->increaseWeakRefCounter();
}

template <typename T>
WeakPtr<T>::WeakPtr(WeakPtr&& ptr) noexcept
    : ptr_(ptr.ptr_), cb_(ptr.cb_) {
    ptr.ptr_ = nullptr;
    ptr.cb_ = nullptr;
}

template <typename T>
WeakPtr<T>::WeakPtr(const scr::SharedPtr<T>& ptr) noexcept
    : ptr_(ptr.ptr_), cb_(ptr.cb_) {
    cb_->increaseWeakRefCounter();
}

template <typename T>
WeakPtr<T>::~WeakPtr() {
    deleteResources();
}

template <typename T>
void WeakPtr<T>::deleteResources() {
    if (cb_) {
        cb_->decreaseWeakRefCounter();
        if (cb_->getSharedCounter() == 0 && cb_->getWeakCounter() == 0) {
            delete cb_;
        }
    }
}

template <typename T>
WeakPtr<T>& WeakPtr<T>::operator=(const WeakPtr& ptr) noexcept {
    if (&ptr != this) {
        deleteResources();
        ptr_ = ptr.ptr_;
        cb_ = ptr.cb_;
        cb_->increaseWeakRefCounter();
    }
    return *this;
}

template <typename T>
WeakPtr<T>& WeakPtr<T>::operator=(WeakPtr&& ptr) noexcept {
    if (&ptr != this) {
        deleteResources();
        ptr_ = ptr.ptr_;
        cb_ = ptr.cb_;
        ptr.ptr_ = nullptr;
        ptr.cb_ = nullptr;
    }
    return *this;
}

template <typename T>
WeakPtr<T>& WeakPtr<T>::operator=(const scr::SharedPtr<T>& ptr) noexcept {
    ptr_ = ptr.ptr_;
    cb_ = ptr.cb_;
    cb_->increaseWeakRefCounter();

    return *this;
}

template <typename T>
scr::SharedPtr<T> WeakPtr<T>::lock() const noexcept {
    return expired() ? scr::SharedPtr<T>() : scr::SharedPtr<T>(*this);
}

template <typename T>
void WeakPtr<T>::reset() noexcept {
    deleteResources();
    ptr_ = nullptr;
    cb_ = nullptr;
}

template <typename T>
size_t WeakPtr<T>::use_count() const noexcept {
    if (cb_) {
        return cb_->getSharedCounter();
    }
    return 0;
}
}  // namespace scr