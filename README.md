# # CSL the CrativeStandardLibrary

Basically just a tiny project to help me with learning and understanding the `c` language more.
You can use it by just simply cloning the projects master branch or copying the `csl` folder.
`csl` is a header only library so no linking or building required, just including the header files wherever needed.

> [!NOTE]
> Currently the only platform i am sure it is working on is linux but as it is only header files, most of the functionallity should translate just as well to Windows or MacOs

## ## Features

## ## Datatypes
### Optional:
- Description:
    - An optional is a datatype that can either have or have not a value. This is indicated through a bool and/or a null or full data parameter. 
The data parameter of the optional can be heap allocated and thus needs to be handled by the caller of the optional.
- Functions:
    - `int csl_validate_optional(csl_optional *o)`:
    Checks wether the optional has valid parameters. For example if the `data` attribute is NULL the `has_value` boolean should also be set to false.
    - `csl_optional csl_optional_some(void *value)`:
    Returns a full optional, with the pointer passed in as the parameter. 
    If that pointer points to heap allocated memory it needs to be handled and freed by the caller.
    - `csl_optional csl_optional_none()`:
    Returns a empty optional with `has_value` set to false and `data` set to NULL.
- Example:
    - XXX TODO XXX
### Pair
- Description:
    - A Pair is a datatype that stores two diffrent variables with equal or diffrent data types. The Implementation of this is being handled by a Macro that takes in the name of the resulting Pair, and both datatypes.
- Example:
    ```c
    CSL_DEFINE_PAIR(pair1, int, float);
    pair1.first = 10;
    pair1.second = 15.4f;
    ```
