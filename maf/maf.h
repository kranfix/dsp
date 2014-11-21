#ifndef github_com_maf_cpp_maf_h
#define github_com_maf_cpp_maf_h

namespace kfx {
  template<type T> class maf {
    public:
      maf(int len);
      T mean();
      void insert(T newvalue);
    private:
      int n; // length
      int p; // pivot
      T * V; // Values array
      T sum;
  };
}

#endif // github_com_maf_cpp_maf_h
