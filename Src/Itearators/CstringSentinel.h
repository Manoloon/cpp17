//
// Created by Manoloon on 25/9/2023.
//

#ifndef CPP17_CSTRINGSENTINEL_H
#define CPP17_CSTRINGSENTINEL_H
class CstringIteratorSentinel{};

class CstringIterator{
    const char* LocalString {nullptr};
public:
    explicit CstringIterator(const char* str):LocalString{str}{}

    char operator *() const {return *LocalString};
    CstringIterator operator ++() {
        ++LocalString;
        return *this;
    }
    bool operator !=(const CstringIteratorSentinel)const {
        return LocalString != nullptr && *LocalString != '\0';
    }
};

class CstringRange{
    const char *LocalStr{nullptr};
public:
    explicit CstringRange(const char *str):LocalStr{str}{}
    CstringIterator begin()const {return CstringIterator{LocalStr};}
    CstringIterator end() const {return {};}
};
#endif //CPP17_CSTRINGSENTINEL_H
