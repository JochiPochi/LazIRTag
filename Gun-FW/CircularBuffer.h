#ifndef CircularBUFFER_H_
#define CircularBUFFER_H_

template <typename Type, typename IndexType, unsigned sz> class CircularBuffer {
public:
  volatile Type            m_buffer[sz];
  volatile IndexType       m_start, m_end,buf_size;

  CircularBuffer() {
    buf_size = m_start = m_end = 0;
  }

  void Push(Type element) {
    m_buffer[m_end] = element;
    if(m_end == sz - 1)
      m_end = 0;
    else
      m_end++;
    buf_size++;
  }

  boolean PushBuffer(Type *elements, unsigned size) { //return true if no overflow
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

  Type GetFront() {
    return m_buffer[m_start];
  }
  
  Type GetBack() {
    if(m_end){
      return m_buffer[m_end-1];
    }
    else {
      return m_buffer[sz-1];
    }
  }

  Type Pop() {
    Type element;
    if(buf_size > 0){
      element = m_buffer[m_start];
      buf_size--;
      if(m_start == sz - 1)
        m_start = 0;
      else
        m_start++;
      return element;
    }
    else {
      return 0;
    }
  }
  
  IndexType GetSize() {
    return buf_size;
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
