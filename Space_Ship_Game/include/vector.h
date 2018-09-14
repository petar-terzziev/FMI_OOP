#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class vector
{
    public:
        typedef T* iterator;
        vector();
        vector(unsigned);
        vector(unsigned,const T&);
        vector(const vector<T>&);
        ~vector();
        unsigned int capacity ()const ;
        unsigned int size() const;
        bool empty () const;
        iterator begin();
        iterator end();
        void push_back(const T&);
        void pop_back();
        void reserve(unsigned);
        void resize(unsigned);
        T& operator [](unsigned);
        const T& operator [](unsigned) const ;
        vector<T>& operator=(const vector<T>&);
        void clear();
        void remove(unsigned);
        bool contains(const T&) const;
        bool operator==(const vector<T>&);
        bool operator!=(const vector<T>&);
    private:
        unsigned thesize;
        unsigned thecapacity;
        iterator buffer;
};
template <class T>
vector<T>::vector():
    thesize(0)
    ,thecapacity(0)
    ,buffer(nullptr)
{}

template <class T>
unsigned vector<T>::size() const
{
  return thesize;
}

template <class T>
unsigned vector<T>::capacity() const
{
  return thecapacity;
}

template <class T>
vector<T>::vector(const vector<T> & rhs):
    thesize(rhs.thesize)
    ,thecapacity(rhs.thecapacity)
    ,buffer(new T[thecapacity])
{
    for(unsigned i=0;i<thesize;i++){
        buffer[i]=rhs.buffer[i];
    }
}
template <class T>
void vector<T>::remove(unsigned idx){
    if(idx>=thesize) throw "Illegal index";
for(int i=idx;i<thesize-1;i++){
    buffer[i]=buffer[i+1];
}
thesize--;
}
template <class T>
vector<T>::vector(unsigned s):
    thesize(s)
    ,thecapacity(s*2)
    ,buffer(new T[thecapacity])

{}

template <class T>
bool vector<T>::empty() const{
return thesize==0;
}
template <class T>
vector<T>::vector(unsigned s,const T& init):
    thesize(s)
    ,thecapacity(s*2)
    ,buffer(new T[thecapacity])
{
    for(unsigned i=0;i<s;i++){
        buffer[i]=init;
    }
}



template <class T>
vector<T>& vector<T>::operator=(const vector<T>& rhs)
{
 if(this!=&rhs){
    delete [] buffer;
    thesize=rhs.thesize;
    thecapacity=rhs.thecapacity;
    buffer=new T[thecapacity];
    for(unsigned i=0;i<thesize;i++){
        buffer[i]=rhs.buffer[i];
    }
 }
 return * this;
}

template <class T>
typename vector<T>::iterator vector<T>::begin()
{
  return buffer;
}
template<class T>
bool vector<T>::operator==(const vector<T>& rhs){
if(thesize!=rhs.thesize) return false;
for(int i=0;i<thesize;i++){
    if(!(buffer[i]==rhs.buffer[i])) return false;
}
return true;
}
template<class T>
bool vector<T>::operator!=(const vector<T>& rhs){
    return !(*this==rhs);
}

template <class T>
typename vector<T>::iterator vector<T>::end()
{
  return buffer+size();
}
template<class T>
void vector<T>::push_back(const T& rhs){
if(thesize>=thecapacity){
    reserve(thesize*2);
}
buffer[thesize++]=rhs;
}

template <class T>
void vector<T>::pop_back(){
thesize--;
}

template <class T>
void vector<T>::reserve(unsigned cap)
{
  T* newbuffer=new T[cap];
  for(unsigned i=0;i<thesize;i++){
    newbuffer[i]=buffer[i];
  }
  thecapacity=cap;
  delete [] buffer;
  buffer=newbuffer;
}
template <class T>
void vector<T>::resize(unsigned s)
{
reserve(s*2);
thesize=s;
}
template <class T>
T& vector<T>::operator[](unsigned idx)
{
    return buffer[idx];
}
template <class T>
const T& vector<T>::operator[](unsigned idx) const
{
    return buffer[idx];
}
template <class T>
bool vector<T>::contains(const T& rhs)const {
for(int i=0;i<thesize;i++){
    if(buffer[i]==rhs) return true;
}
return false;
}
template <class T>
vector<T>::~vector()
{
    delete [] buffer;
}
template <class T>
void vector<T>::clear(){
thecapacity=0;
thesize=0;
buffer=nullptr;
}
#endif // VECTOR_H
