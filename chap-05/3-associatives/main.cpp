#include "keys.h"

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_set>
#include <utility>

int main()
{
    std::set<ComparableDog> dogs;

    ComparableDog medor { "medor", "labrador" };
    dogs.emplace(medor);

    ComparableDog gus { "gus", "bordercollie" };
    dogs.emplace(gus);

    std::cout << dogs.size() << std::endl;
    ComparableDog medor_clone = medor;
    dogs.emplace(medor_clone);

    std::cout << dogs.size() << std::endl;

    std::unordered_set<HashableDog> hdogs;

    HashableDog hgus { "gus", "bordercollie" };

    HashableDog hmedor { "medor", "labrador" };
    HashableDog clone { hmedor };

    hdogs.emplace(hgus);
    hdogs.emplace(hmedor);
    hdogs.emplace(clone);
    std::cout << hdogs.size() << std::endl;

    using Owner = std::pair<std::string, std::string>;
    std::map<ComparableDog, Owner> owners_by_dog;

    ComparableDog zim { "zim", "poodle" };
    ComparableDog flippy { "flippy", "spaniel" };

    owners_by_dog.insert(std::make_pair(medor, Owner { "Claire", "David" }));
    owners_by_dog.insert_or_assign(gus, Owner { "Marc", "Zipstein" });
    owners_by_dog.emplace(zim, Owner { "Céline", "Noël" });
    owners_by_dog.try_emplace(flippy, "Vincent", "Nozick");

    owners_by_dog.emplace(gus, Owner { "Claire", "David" });
    // -> gus is still owned by Marc (emplace does not modify values with existing keys, neither does insert
    // or try_emplace)

    owners_by_dog.insert_or_assign(gus, Owner { "Vincent", "Nozick" });
    // -> gus is now owned by Vincent (insert_or_assign reassign values with existing keys)

    return 0;
}