#ifndef CircularBUFFER_H_
#define CircularBUFFER_H_

template <typename T, typename IndexType, unsigned sz> class CircularBuffer {
public:
  volatile T               m_buffer[sz];
  volatile IndexType       m_start, m_end,buf_size;
  volatile uint32_t        prevTime;
  volatile boolean         lastState;

  CircularBuffer() {
    buf_size = m_start = m_end = 0;
  }

  void Push(T element) {
    m_buffer[m_end] = element;
    if(m_end == sz - 1)
      m_end = 0;
    else
      m_end++;
    buf_size++;
  }


  boolean PushBuffer(T *elements, unsigned size) { //return true if no overflow
    buf_size += size;
    if(size == 0) {
      return true;
    }
    if(m_end + size < sz) {
      for(unsigned int i = 0; i < size; i++) {
        m_buffer[m_end++] = *elements++;
      }
    } 
    else {
      while(m_end != sz) {
        m_buffer[m_end++] = *elements++;
        size--;
      }
      m_end = 0;
      while(size--) {
        m_buffer[m_end++] = *elements++;
      }
    }
    return true;
  }

  T GetFront() {
    return m_buffer[m_start];
  }

  T Pop() {
    T element;
    element = m_buffer[m_start];
    buf_size--;
    if(m_start == sz - 1)
      m_start = 0;
    else
      m_start++;
    return element;
  }

  inline boolean IsEmpty() {
    return (m_end == m_start);
  }


  boolean IsFull() {
    boolean full;
    if(m_start == 0)
      full = (m_end == sz - 1);
    else
      full = (m_end + 1 == m_start);
    return full;
  }
};

class CircularBufferErrorHandler {
public:
  static inline void Overflow() {
    //volatile int x = 0;
  }
};
#endif /* CircularBUFFER_H_ */
