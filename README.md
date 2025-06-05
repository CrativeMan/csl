# # CSL the CrativeStandardLibrary

Basically just a tiny project to help me with learning and understanding the `c` language more.
You can use it by just simply cloning the projects master branch or copying the `csl` folder.
`csl` is a header only library so no linking or building required, just including the header files wherever needed.

> [!NOTE]
> Currently the only platform i am sure it is working on is linux but as it is only header files, most of the functionallity should translate just as well to Windows or MacOs

## ## Features

## ## Datatypes

### ### Optional:

- Description: - An optional is a datatype that can either have or have not a value. This is indicated through a bool and/or a null or full data parameter.
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

  ```c
  csl_optional db_request() {
      int value;
      /* snip */
      return csl_optional_some(&value);
  }

  csl_optional rv = db_request();
  assert(rv.has_value == true);
  ```

### ### Pair

- Description:
  - A Pair is a datatype that stores two different variables with equal or different data types. The Implementation of this is being handled by a Macro that takes in the name of the resulting Pair, and both datatypes.
  - It has a few standard types that can be used to create a pair more quickly using these basic types.
- Example:
  ```c
  CSL_DEFINE_PAIR(pair1, int, float);
  pair1.first = 10;
  pair1.second = 15.4f;
  ```

### ### Result

- Description:
  - Results are a datatype that holds a pointer to a `value` a `csl_result_status` and a const char `error_message`.
  - A `csl_result_status` is an enum with 3 diffrent values: `CSL_RESULT_OK`, `CSL_RESULT_WARN`, `CSL_RESULT_ERROR`.
- Functions:
  - `csl_result csl_result_ok(void* value)`:
    Returns an ok result.
  - `csl_result csl_result_warn(void* value, const char *message)`:
    Returns a warn result with an error message.
  - `csl_result csl_result_ok(void* value, const char *message)`:
    Returns an error result with an error message.
