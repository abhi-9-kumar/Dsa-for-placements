 if (root == nullptr) {
            // If the tree is empty, return an appropriate value
            // In some cases, it might be appropriate to return INT_MAX or INT_MIN or throw an exception
            return -1; // Adjust this based on your use case
        }

        // Traverse to the leftmost node
        while (root->left != nullptr) {
            root = root->left;
        }

        // The leftmost node contains the minimum value
        return root->data;