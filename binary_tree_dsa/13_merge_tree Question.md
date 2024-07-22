# Merging Rules for Two Config Trees
Guiding principle: use t1's node ordering, but t2's node values.
When node n1 from t1 is merged with node n2 from t2, the following rules are applied
to derive the merged node m (see merging example below):

## Rules:
1. The merged node m will take the name property of n1 and the value property of n2. 2. The k-th child node of n1 with the name X will be matched and merged with the k-th child node of n2 with the same name X.
2. The merged node m will contain all the child nodes of n1 in the same order, but they may have different value properties and child nodes depending on whether they have been merged with the child nodes of n2.
3. Unmatched child nodes of n1 will be left unchanged in the merged node m.
4. Unmatched child nodes of n2 will be added unchanged in the same order in n2 to the merged node m after the child nodes of n1.

## Input and Output
Input:
    t1 -> root node of Tree-1
    t2 -> root node of Tree-2

Output:
    t1 with merged values from t2 by following above rules

## Example

Input:

```sh
    Tree-1:
    └──env (base)
        ├──name (some name)
        │   ├──metadata (some metadata)
        │   └──image (common_payment_app_image)
        │       └──registry (registry.k8s.io)
        ├──port (0000)
        ├──name (sample_module)
        ├──kind (Pod)
        ├──port (27017)
        └──max_connection (4)

    Tree-2:
    └──env (Staging)
        ├──name (payment_app)
        │   ├──metadata (payment-app metadata)
        │   └──apiVersion (v1.0)
        ├──internalEndpoint (http://internal.ai)
        ├──port (8080)
        ├──name (core_payment_module)
        └──port (9000)
```

Output:

```sh
    Tree-Result:
    └──env (Staging)
        ├──name (some name)
        │   ├──metadata (payment-app metadata)
        │   ├──image (common_payment_app_image)
        │   │   └──registry (registry.k8s.io)
        │   └──apiVersion (v1.0)
        ├──port (8080)
        ├──name (core_payment_module)
        ├──kind (Pod)
        ├──port (9000)
        ├──max_connection (4)
        └──internalEndpoint (http://internal.ai)
```