#ifndef github_com_maf_cpp_maf_h
#define github_com_maf_cpp_maf_h

template<class T, int len> class maf {
  public:
    maf();
    T mean();
    void insert(T newvalue);
  private:
    int n; // length
    int p; // pivot
    T * V; // Values array
    T sum;
};


#endif // github_com_maf_cpp_maf_h
