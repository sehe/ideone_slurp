// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2013-07-25 12:01:13
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <vector>
#include <memory>

typedef std::vector<int> CBuffer;

static CBuffer& PostProcess(CBuffer& data)  { 
    for(auto& el : data)
        el /= 2;
    return data;
}

struct CSource
{
    CSource() : _data(std::make_shared<CBuffer>(10)) {}

    std::shared_ptr<CBuffer>       GetData()       { return _data; }
    std::shared_ptr<const CBuffer> GetData() const { return _data; }

  private:
    std::shared_ptr<CBuffer> _data;
};

struct CPlug
{
    CPlug(bool postProcess = true) : m_postProcess(postProcess) { }

    std::shared_ptr<const CBuffer> ProcessData() const
    {
        /* get the data from the source, implicitely const */
        auto buffer = m_source.GetData();

        if (!m_postProcess)
            return buffer;

        // clone!
        auto clone = *buffer;
        return std::make_shared<CBuffer>(PostProcess(clone));
    }

  private:
    bool    m_postProcess;
    CSource m_source;
};

int main()
{
    CPlug intance;
    auto x = instance.ProcessData();
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp: In function ‘int main()’:
prog.cpp:48:14: error: ‘instance’ was not declared in this scope
prog.cpp:48:35: error: unable to deduce ‘auto’ from ‘<expression error>’
prog.cpp:48:10: warning: unused variable ‘x’ [-Wunused-variable]

#endif
