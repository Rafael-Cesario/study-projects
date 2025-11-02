import { Prisma } from "../generated/prisma/client";
import type { Request, Response, NextFunction } from "express";

export const errorHandler = (error: Error, _req: Request, res: Response, _next: NextFunction) => {
  const message = "Internal server Error";

  if (error instanceof Prisma.PrismaClientKnownRequestError) {
    if (error.code === "P2002") res.status(400).json({ error: "Email must be unique" });
    return;
  }

  res.status(500).json({ error: message });
};
