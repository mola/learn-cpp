#ifndef REGISTRY_H
#define REGISTRY_H

#include <map>
#include <string>

class Registry
{
public:
    static Registry* instance()
    {
        if (!mInstamce)
        {
            mInstamce = new Registry();
        }

        return mInstamce;
    }

    void  setProperty(std::string key, std::string value)
    {
        properties[key] = value;
    }

    std::string  property(std::string key)
    {
        if (properties.find(key) != properties.end())
        {
            return properties[key];
        }

        return "No key defined .";
    }

private:
    Registry();

private:
    static Registry *mInstamce;

    std::map<std::string, std::string>  properties;
};

#endif // REGISTRY_H
