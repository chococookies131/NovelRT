// Copyright © Matt Jones and Contributors. Licensed under the MIT Licence (MIT). See LICENCE.md in the repository root for more information.

#ifndef NOVELRT_ECS_ENTITYCACHE_H
#define NOVELRT_ECS_ENTITYCACHE_H

#include "EcsUtils.h"
#include "SparseSet.h"
#include <vector>
namespace NovelRT::Ecs
{
    /**
     * @brief A cache for storing entity update instructions concurrently. In a regular ECS instance, you should not be instantiating this yourself.
     * 
     */
    class EntityCache
    {
        private:
        SparseSet<size_t, std::vector<EntityId>> _updateVectors;
        std::vector<EntityId> _entitiesToRemoveThisFrame;

        public:
        /**
         * @brief Constructs a new instance of EntityCache with the given thread pool size.
         * 
         * @param poolSize The amount of worker threads to allocate for.
         */
        EntityCache(size_t poolSize) noexcept;

        /**
         * @brief Fetches an immutable reference to the entities to be deleted this particular iteration of the ECS.
         * 
         * This is a pure method. Calling this without using the result has no effect and introduces overhead for calling a method.
         * 
         * @return const std::vector<EntityId>& The collection of EntityId instances to delete.
         */
        [[nodiscard]] inline const std::vector<EntityId>& GetEntitiesToRemoveThisFrame() const noexcept
        {
            return _entitiesToRemoveThisFrame;
        }

        /**
         * @brief Queues an entity for removal in the next frame.
         * 
         * @param poolId The current worker thread's pool ID the removal instruction is coming from.
         * @param entityToRemove The EntityId to delete.
         */
        void RemoveEntity(size_t poolId, EntityId entityToRemove) noexcept;

        /**
         * @brief Propagates deletion requests from worker threads to the main thread. Once this is called, the data can be accessed from EntityCache::GetEntitiesToRemoveThisFrame.
         * 
         * In a standard ECS instance, This method should not be called by the developer.
         */
        void ProcessEntityDeletionRequestsFromThreads() noexcept;
    };
}

#endif //!NOVELRT_ECS_ENTITYCACHE_H