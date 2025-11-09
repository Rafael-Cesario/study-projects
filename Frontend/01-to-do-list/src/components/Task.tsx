"use client";

import { ITask, Status } from "@/app/page";
import { useState } from "react";

interface TaskProps {
  props: {
    task: ITask;
    removeTask: (id: string) => void;
    updateTask: (task: ITask) => void;
  };
}

export function Task({ props: { task, removeTask, updateTask } }: TaskProps) {
  const [title, setTitle] = useState(task.title);
  const [status, setStatus] = useState(task.status);
  const [isEditable, setIsEditable] = useState(false);

  const nextStatus: Record<Status, Status> = {
    next: "current",
    current: "done",
    done: "next",
  };

  const borderStatus = {
    next: "border-neutral-600",
    current: "border-blue-500",
    done: "border-green-500",
  };

  return (
    <div
      className={`m-[1.2rem_0] flex flex-row justify-between bg-neutral-900 p-[10px_20px] border-l-5 ${borderStatus[status]}`}
    >
      {isEditable ? (
        <>
          <input
            autoFocus
            className="grow-4 mr-4 outline-none border-b-blue-500 border-b"
            type="text"
            value={title}
            onChange={(e) => setTitle(e.target.value)}
          />

          <button
            onClick={() => setStatus(nextStatus[status])}
            className="mr-4 cursor-pointer text-neutral-600 hover:text-white"
          >
            Status
          </button>

          <button
            className="mr-4 text-white cursor-pointer hover:text-green-500"
            onClick={() => (
              updateTask({ id: task.id, title: title === "" ? task.title : title, status }), setIsEditable(false)
            )}
          >
            Salvar
          </button>
        </>
      ) : (
        <>
          <p className="grow-4 mr-4">{task.title}</p>

          <button className="cursor-pointer mr-4 text-neutral-600 hover:text-white" onClick={() => setIsEditable(true)}>
            Editar
          </button>
        </>
      )}

      <button onClick={() => removeTask(task.id)} className="text-neutral-600 cursor-pointer hover:text-white">
        Excluir
      </button>
    </div>
  );
}
