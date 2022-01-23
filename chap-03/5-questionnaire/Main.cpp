#include <iostream>
#include <memory>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

struct Resource
{
    Resource(const std::string& content)
        : _content { content }
    {}

    std::string _content;
};

// Index objects of type Resource and handle their lifespans.
class ResourceManager
{

    friend std::ostream& operator<<(std::ostream& stream, const ResourceManager& rm)
    {

        stream << "_resources.capacity = " << rm._resources.capacity() << std::endl;
        for (auto i = 0u; i < rm._resources.capacity(); i++)
        {
            if (rm._resources[i] != nullptr)
            {
                stream << "_resources[" << i << "] = \"" << rm._resources[i].get()->_content << "\""
                       << std::endl;
            }
            else
            {
                stream << "_resources[" << i << "] is nullptr" << std::endl;
            }
        }
        return stream;
    }

public:
    // Create a new resource.
    // Return the index where the resource was created.
    size_t create(const std::string& content)
    {
        _resources.emplace_back(std::make_unique<Resource>(content));
        return _resources.capacity() - 1;
    }

    // Destroy the resource at the given index.
    // The other elements keep the same index, we do not reorganize the array.
    void destroy(size_t index) { _resources[index].reset(); }

    // Take the ownership of an existing resource.
    // Return the index where the resource was placed.
    size_t acquire(std::unique_ptr<Resource> resource)
    {
        _resources.emplace_back(std::move(resource));
        return _resources.capacity() - 1;
    }

    // Transfer the resource at the given index to the caller.
    std::unique_ptr<Resource> yield(size_t index) { return std::move(_resources[index]); }

    // Provide access to the resource at the given index.
    Resource& get(size_t index) const { return *(_resources[index]); }

private:
    std::vector<std::unique_ptr<Resource>> _resources;
};

int main()
{

    ResourceManager rm {};

    // std::cout << rm << std::endl;

    std::cout << "rm.create() : " << rm.create("First content") << std::endl;
    std::cout << rm << std::endl;

    auto resource = rm.get(0);
    std::cout << rm << std::endl;

    std::cout << "resource._content  := " << resource._content << std::endl;
    std::cout << rm << std::endl;

    /*
        std::cout << "rm.create() : " << rm.create("First content") << std::endl;

        std::cout << rm << std::endl;

        std::cout << "rm.create() : " << rm.create("Second content") << std::endl;

        std::cout << rm << std::endl;


        rm.destroy(0);
        std::cout << "----- rm.destroy(0) -----" << std::endl;
        std::cout << rm << std::endl;

        std::cout << "----- rm.acquire(tmp) -----" << std::endl;
        std::unique_ptr<Resource> tmp = std::make_unique<Resource>("Test.aquire");
        std::cout << "tmp : " << tmp.get()->_content << std::endl;
        std::cout << "rm.acquire(tmp) : " << rm.acquire(std::move(tmp)) << std::endl;
        std::cout << rm << std::endl;

        std::cout << "----- rm.yield(1) -----" << std::endl;
        std::unique_ptr<Resource> extract = rm.yield(1);
        std::cout << "extract = " << extract.get()->_content << std::endl;
        std::cout << rm << std::endl;

        std::cout << "----- test move swap 3 -> 4  -----" << std::endl;
        std::cout << "rm.create() : " << rm.create("Swap") << std::endl;
        std::cout << rm << std::endl;
        rm.acquire(rm.yield(3));
        std::cout << rm << std::endl;
    */

    return 0;
}
